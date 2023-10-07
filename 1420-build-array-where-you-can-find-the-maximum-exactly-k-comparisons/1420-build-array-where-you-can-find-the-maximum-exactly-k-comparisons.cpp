class Solution {
    const int Mod = 1e9 + 7;
public:
    int numOfArrays(int n, int m, int k)
    {
        long long Memo[51][101][51];
        long long Prev[51][101][51];
        
        for(int i = 0; i <= m; i++)
        {
            Memo[1][i][1] = 1;
            Prev[1][i][1] = i;
        }
        
        for(int Length = 2; Length <= n; Length++)
        {
            for(int Max = 1; Max <= m; Max++)
            {
                for(int Cost = 1; Cost <= k; Cost++)
                {
                    Memo[Length][Max][Cost] = (Max * Memo[Length - 1][Max][Cost]) % Mod;
                    
                    Memo[Length][Max][Cost] += Prev[Length - 1][Max - 1][Cost - 1];
                    Memo[Length][Max][Cost] %= Mod;
                    
                    Prev[Length][Max][Cost] = (Prev[Length][Max - 1][Cost] + Memo[Length][Max][Cost]) % Mod;
                }
            }
        }
        
        int Result = static_cast<int>(Prev[n][m][k]);
        return Result;
    }
};