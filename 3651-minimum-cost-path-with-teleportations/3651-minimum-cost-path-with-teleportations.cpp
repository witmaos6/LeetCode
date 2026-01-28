class Solution {
    using Pair = pair<int, int>;
public:
    int minCost(vector<vector<int>>& grid, int k)
    {
        const int Rows = static_cast<int>(grid.size());
        const int Cols = static_cast<int>(grid[0].size());
        const int INF = 1e9;
        const int Max = 10000;

        vector<vector<Pair>> Memo(Max + 1);
        for(int i = 0; i < Rows; i++)
        {
            for(int j = 0; j < Cols; j++)
            {
                Memo[grid[i][j]].push_back({i,j});
            }
        }

        vector<vector<vector<int>>> Dist(k + 1, vector<vector<int>>(Rows, vector<int>(Cols, INF)));
        Dist[0][0][0] = 0;

        for(int t = 0; t <= k; t++)
        {
            priority_queue<Pair, vector<Pair>, greater<>> MinHeap;
            for(int i = 0; i < Rows; i++)
            {
                for(int j = 0; j < Cols; j++)
                {
                    if(Dist[t][i][j] != INF)
                    {
                        MinHeap.push({Dist[t][i][j], i * Cols + j});
                    }
                }
            }

            while(!MinHeap.empty())
            {
                auto[D, Pos] = MinHeap.top();
                MinHeap.pop();

                int R = Pos / Cols;
                int C = Pos % Cols;
                if(D > Dist[t][R][C])
                    continue;

                int DR[2] = {0,1};
                int DC[2] = {1,0};

                for(int i = 0; i < 2; i++)
                {
                    int NR = R + DR[i];
                    int NC = C + DC[i];

                    if(NR < Rows && NC < Cols)
                    {
                        if(Dist[t][NR][NC] > D + grid[NR][NC])
                        {
                            Dist[t][NR][NC] = D + grid[NR][NC];
                            MinHeap.push({Dist[t][NR][NC], NR * Cols + NC});
                        }
                    }
                }
            }

            if(t < k)
            {
                vector<int> MinCost(Max + 1, INF);
                for (int i = 0; i < Rows; ++i)
                {
                    for (int j = 0; j < Cols; ++j)
                    {
                        MinCost[grid[i][j]] = min(MinCost[grid[i][j]], Dist[t][i][j]);
                    }
                }

                vector<int> Suffix(Max + 2, INF);
                for (int v = Max; v >= 0; --v)
                {
                    Suffix[v] = min(Suffix[v + 1], MinCost[v]);
                }

                for (int v = 0; v <= Max; ++v)
                {
                    if (Suffix[v] == INF)
                        continue;

                    for (auto& [r, c] : Memo[v])
                    {
                        Dist[t + 1][r][c] = min(Dist[t + 1][r][c], Suffix[v]);
                    }
                }
            }
        }

        int Result = INF;
        for(int t = 0; t <= k; t++)
        {
            Result = min(Result, Dist[t][Rows - 1][Cols - 1]);
        }
        return Result >= INF ? -1 : Result;
    }
};