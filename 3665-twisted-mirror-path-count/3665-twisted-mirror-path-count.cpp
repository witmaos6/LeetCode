class Solution {
    const int Mat[2][2][2] = { { {1,1}, {1,1} }, { {0,1}, {1,0} } };
    const int Mod = 1e9 + 7;
public:
    int uniquePaths(vector<vector<int>>& grid)
    {
        const int Rows = grid.size();
        const int Cols = grid[0].size();
        int Left = 0;
        vector<int> Memo(Cols);
        Memo[0] = 1;

        for(int i = 0; i < Rows; i++)
        {
            Left = 0;
            for(int j = 0; j < Cols; j++)
            {
                int C = grid[i][j];
                int Top = Memo[j];

                Memo[j] = (Left * Mat[C][1][0] + Top * Mat[C][1][1]) % Mod;
                Left = (Left * Mat[C][0][0] + Top * Mat[C][0][1]) % Mod;
            }
        }
        return Left;
    }
};