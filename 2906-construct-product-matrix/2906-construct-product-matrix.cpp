class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid)
    {
        const int Rows = grid.size();
        const int Cols = grid[0].size();
        const long long Mod = 12345;
        long long Pref = 1;
        long long Suff = 1;

        vector<vector<int>> P(Rows, vector<int>(Cols));
        for(int i = 0; i < Rows; i++)
        {
            for(int j = 0; j < Cols; j++)
            {
                P[i][j] = Pref;
                Pref = (Pref * grid[i][j]) % Mod;
            }
        }
        
        for(int i = Rows - 1; i >= 0; i--)
        {
            for(int j = Cols - 1; j >= 0; j--)
            {
                P[i][j] = (P[i][j] * Suff) % Mod;
                Suff = (Suff * grid[i][j]) % Mod;
            }
        }
        return P;
    }
};