class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit)
    {
        const int Mod = 1e9 + 7;

        vector<vector<long long>> Memo0(zero + 1, vector<long long>(one + 1, 0));
        vector<vector<long long>> Memo1(zero + 1, vector<long long>(one + 1, 0));

        for(int i = 1; i <= min(zero, limit); i++)
        {
            Memo0[i][0] = 1;
        }
        for(int i = 1; i <= min(one, limit); i++)
        {
            Memo1[0][i] = 1;
        }

        for(int i = 0; i <= zero; i++)
        {
            for(int j = 0; j <= one; j++)
            {
                if(i == 0 && j == 0)
                    continue;
                
                if(i > 0 && j > 0)
                {
                    Memo0[i][j] = (Memo0[i - 1][j] + Memo1[i - 1][j]) % Mod;
                    if(i - limit - 1 >= 0)
                    {
                        Memo0[i][j] = (Memo0[i][j] - Memo1[i - limit - 1][j] + Mod) % Mod;
                    }

                    Memo1[i][j] = (Memo1[i][j - 1] + Memo0[i][j - 1]) % Mod;
                    if(j - limit - 1 >= 0)
                    {
                        Memo1[i][j] = (Memo1[i][j] - Memo0[i][j - limit - 1] + Mod) % Mod;
                    }
                }
            }
        }
        return (Memo0[zero][one] + Memo1[zero][one]) % Mod;
    }
};