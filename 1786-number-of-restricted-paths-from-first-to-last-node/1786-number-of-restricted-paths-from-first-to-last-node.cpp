class Solution {
    using Node = pair<int, int>;
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges)
    {
        const int Mod = 1e9 + 7;

        vector<vector<Node>> Graph(n + 1);
        for(const vector<int>& Edge : edges)
        {
            Graph[Edge[0]].push_back({Edge[1], Edge[2]});
            Graph[Edge[1]].push_back({Edge[0], Edge[2]});
        }

        vector<int> Count(n + 1);
        vector<int> MinDist(n + 1, INT_MAX);
        Count[n] = 1;
        MinDist[n] = 0;

        priority_queue<Node, vector<Node>, greater<Node>> MinHeap;
        MinHeap.push({0, n});

        while(!MinHeap.empty())
        {
            auto[Dist, Curr] = MinHeap.top();
            MinHeap.pop();

            if(Dist != MinDist[Curr])
                continue;

            for(auto& [Adj, Cost] : Graph[Curr])
            {
                if(MinDist[Adj] > Dist + Cost)
                {
                    MinDist[Adj] = Dist + Cost;
                    MinHeap.push({MinDist[Adj], Adj});
                    Count[Adj] = (Count[Adj] + Count[Curr]) % Mod;
                }
                else if(MinDist[Adj] > Dist)
                {
                    Count[Adj] = (Count[Adj] + Count[Curr]) % Mod;
                }
            }
        }
        return Count[1];
    }
};