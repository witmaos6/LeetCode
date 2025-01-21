class Solution {
public:
    long long gridGame(vector<vector<int>>& grid)
    {
        const int N = static_cast<int>(grid[0].size());
        if(N == 1)
            return 0;

        long long TopPoint = 0;
        for(int i = 0; i < N; i++)
        {
            TopPoint += grid[0][i];
        }

        long long BottomPoint = 0;
        long long Result = LLONG_MAX;
        for(int i = 0; i < N; i++)
        {
            TopPoint -= grid[0][i];

            long long MaxPoint = max(TopPoint, BottomPoint);
            Result = min(Result, MaxPoint);

            BottomPoint += grid[1][i];
        }

        return Result;
    }
};