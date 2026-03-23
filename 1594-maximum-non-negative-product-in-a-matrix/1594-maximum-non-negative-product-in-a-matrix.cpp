class Solution {
    using Pair = pair<long long, long long>; // first = max, second = min
public:
    int maxProductPath(vector<vector<int>>& grid)
    {
        const int Mod = 1e9 + 7;
        const int Rows = static_cast<int>(grid.size());
        const int Cols = static_cast<int>(grid[0].size());

        vector<vector<Pair>> Memo(Rows, vector<Pair>(Cols));
        Memo[0][0].first = Memo[0][0].second = grid[0][0];

        for(int i = 1; i < Rows; i++)
        {
            long long Temp = (Memo[i - 1][0].first * grid[i][0]) % Mod;
            Memo[i][0].first = Memo[i][0].second = Temp;
        }
        for(int i = 1; i < Cols; i++)
        {
            long long Temp = (Memo[0][i - 1].first * grid[0][i]) % Mod;
            Memo[0][i].first = Memo[0][i].second = Temp;
        }

        for(int i = 1; i < Rows; i++)
        {
            for(int j = 1; j < Cols; j++)
            {
                long long UpMin = (Memo[i - 1][j].second * grid[i][j]);
                long long UpMax = (Memo[i - 1][j].first * grid[i][j]);
                long long LeftMin = (Memo[i][j - 1].second * grid[i][j]);
                long long LeftMax = (Memo[i][j - 1].first * grid[i][j]);

                Memo[i][j].second = min({UpMin, UpMax, LeftMin, LeftMax});
                Memo[i][j].first = max({UpMin, UpMax, LeftMin, LeftMax});
            }
        }
        if(Memo.back().back().first < 0)
            return -1;
        
        return Memo.back().back().first % Mod;
    }
};