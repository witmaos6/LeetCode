class Solution {
    using Pair = pair<int, int>;
    using LPair = pair<long long, int>;
public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector<vector<Pair>> Graph(n);
        for(const vector<int>& Road : roads)
        {
            Graph[Road[0]].push_back({Road[1], Road[2]});
            Graph[Road[1]].push_back({Road[0], Road[2]});
        }

        vector<long long> Dist(n, LLONG_MAX);
        Dist[0] = 0;
        vector<int> Ways(n, 0);
        Ways[0] = 1;
        priority_queue<LPair, vector<LPair>, greater<>> MinHeap;
        MinHeap.push({0, 0});
        const int Mod = 1e9 + 7;
        while(!MinHeap.empty())
        {
            auto [D, Node] = MinHeap.top();
            MinHeap.pop();

            if(D > Dist[Node])
            {
                continue;
            }

            for(const auto& [Next, Time] : Graph[Node])
            {
                long long NextTime = Dist[Node] + Time;
                if(NextTime < Dist[Next])
                {
                    Dist[Next] = Dist[Node] + Time;
                    Ways[Next] = Ways[Node];
                    MinHeap.push({Dist[Next], Next});
                }
                else if(NextTime == Dist[Next])
                {
                    Ways[Next] = (Ways[Next] + Ways[Node]) % Mod;
                }
            }
        }
        return Ways[n - 1];
    }
};