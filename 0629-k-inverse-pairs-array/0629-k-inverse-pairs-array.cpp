class Solution {
public:
    int kInversePairs(int n, int k)
    {
        const int Mod = 1e9 + 7;
        vector<vector<int>> Memo(n + 1, vector<int>(k + 1));
        Memo[0][0] = 1;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= k; j++)
            {
                int Range = min(i - 1, j);
                for(int Val = 0; Val <= Range; Val++)
                {
                    if(j - Val >= 0)
                    {
                        Memo[i][j] = (Memo[i][j] + Memo[i - 1][j - Val]) % Mod;
                    }
                }
            }
        }
        
        return Memo[n][k];
    }
};