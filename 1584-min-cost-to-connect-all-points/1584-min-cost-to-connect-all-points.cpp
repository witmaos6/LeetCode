class Solution {
    typedef pair<int, int> Point;
public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int N = static_cast<int>(points.size());
        vector<bool> Visited(N);
        
        unordered_map<int, int> Graph;
        
        for(int i = 0; i < N; i++)
        {
            Graph[i] = INT_MAX;
        }
        Graph[0] = 0;
        
        auto cmp = [](Point Left, Point Right) { return Left.first > Right.first; };
        priority_queue<Point, vector<Point>, decltype(cmp)> MinHeap(cmp);
        MinHeap.push({0, 0});
        
        int MinCost = 0;
        
        while (!MinHeap.empty())
        {
            auto [W, U] = MinHeap.top();
            MinHeap.pop();
            
            if (Visited[U] || Graph[U] < W)
            {
                continue;
            }
            
            Visited[U] = true;
            MinCost += W;
            
            for (int i = 0; i < N; i++)
            {
                if (!Visited[i])
                {
                    int Distance = GetDistance(points[U], points[i]);
                    
                    if (Distance < Graph[i])
                    {
                        Graph[i] = Distance;
                        MinHeap.push({Distance, i});
                    }
                }
            }
        }
        
        return MinCost;
    }
    
private:
    int GetDistance(vector<int>& P1, vector<int>& P2)
    {
        return abs(P1[0] - P2[0]) + abs(P1[1] - P2[1]);
    }
};