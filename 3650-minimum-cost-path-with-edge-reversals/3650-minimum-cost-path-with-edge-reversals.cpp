class Solution {
    using Pair = pair<int, int>;
    
public:
    int minCost(int n, vector<vector<int>>& edges)
    {
        vector<vector<Pair>> Graph(n);

        for(vector<int>& Edge : edges)
        {
            Graph[Edge[0]].push_back({Edge[1], Edge[2]});
            Graph[Edge[1]].push_back({Edge[0], Edge[2] * 2});
        }

        vector<int> D(n, 1e9);
        priority_queue<Pair, vector<Pair>, greater<Pair>> MinHeap;
        MinHeap.push({0,0});
        D[0] = 0;

        while(!MinHeap.empty())
        {
            auto[Dis, U] = MinHeap.top();
            MinHeap.pop();

            if(Dis != D[U])
                continue;

            if(U == n - 1)
                return Dis;

            for(auto& [V, W] : Graph[U])
            {
                if(Dis + W < D[V])
                {
                    D[V] = Dis + W;
                    MinHeap.push({D[V], V});
                }
            }
        }
        return -1;
    }
};