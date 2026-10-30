class Solution {
    using Point = pair<int, int>;
    using State = tuple<long long, int, int>;
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k)
    {
        vector<vector<Point>> Graph(n);
        for(vector<int>& Edge : edges)
        {
            Graph[Edge[0]].push_back({Edge[1], Edge[2]});
        }

        vector<int> Memo(n, k + 1);
        priority_queue<State, vector<State>, greater<>> MaxHeap;
        MaxHeap.emplace(0, 1, 0);

        while(!MaxHeap.empty())
        {
            auto[D, Run, X] = MaxHeap.top();
            MaxHeap.pop();

            if(Run >= Memo[X])
                continue;
            
            if(X == n - 1)
                return D;
            
            Memo[X] = Run;
            for(auto& [Next, W] : Graph[X])
            {
                int R = labels[Next] == labels[X] ? Run + 1 : 1;
                if(R < Memo[Next])
                    MaxHeap.emplace(D + W, R, Next);
            }
        }
        return -1;
    }
};