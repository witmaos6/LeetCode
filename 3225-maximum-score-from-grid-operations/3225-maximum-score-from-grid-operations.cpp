class Solution {
    using Pair = pair<long long, long long>;
public:
    long long maximumScore(vector<vector<int>>& grid)
    {
        const int N = grid.size();
        if(N == 1)
            return 0;

        vector<vector<long long>> ColSum(N, vector<long long>(N + 1));
        vector<vector<Pair>> Memo(N, vector<Pair>(N + 1));

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                ColSum[j][i + 1] = ColSum[j][i] + grid[i][j];
            }
        }

        for(int j = 1; j < N; j++)
        {
            for(int B0 = 0; B0 <= N; B0++)
            {
                auto [P0, P1] = Memo[j - 1][B0];

                for(int B1 = 0; B1 <= N; B1++)
                {
                    bool IsBigger = B1 > B0;

                    long long PrevX = IsBigger ? (ColSum[j - 1][B1] - ColSum[j - 1][B0]) : 0;
                    long long CurrX = !IsBigger ? (ColSum[j][B0] - ColSum[j][B1]) : 0;

                    Memo[j][B1].first = max(Memo[j][B1].first, max(PrevX + P0, P1));
                    Memo[j][B1].second = max(Memo[j][B1].second, CurrX + max(PrevX + P0, P1));
                }
            }
        }

        long long Result = 0;
        for(int B = 0; B <= N; B++)
        {
            Result = max(Result, Memo[N - 1][B].second);
        }
        return Result;
    }
};