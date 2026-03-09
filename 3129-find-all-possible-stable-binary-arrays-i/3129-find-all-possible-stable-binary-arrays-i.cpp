class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit)
    {
        const int Mod = 1e9 + 7;

        vector<vector<int>> Memo0(zero + 1, vector<int>(one + 1, 0));
        vector<vector<int>> Memo1(zero + 1, vector<int>(one + 1, 0));

        for(int i = 1; i <= min(zero, limit); i++)
        {
            Memo0[i][0] = 1;
        }
        for(int i = 1; i <= min(one, limit); i++)
        {
            Memo1[0][i] = 1;
        }

        for(int i = 1; i <= zero; i++)
        {
            for(int j = 1; j <= one; j++)
            {
                for(int k = 1; k <= min(limit, i); k++)
                {
                    Memo0[i][j] = (Memo0[i][j] + Memo1[i - k][j]) % Mod;
                }
                for(int k = 1; k <= min(limit, j); k++)
                {
                    Memo1[i][j] = (Memo1[i][j] + Memo0[i][j - k]) % Mod;
                }
            }
        }
        return (Memo0[zero][one] + Memo1[zero][one]) % Mod;
    }
};