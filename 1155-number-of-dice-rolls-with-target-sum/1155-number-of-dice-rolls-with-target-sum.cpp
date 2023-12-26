class Solution {
    const int Mod = 1e9 + 7;
public:
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> Memo(n + 1, vector<int>(target + 1));
        Memo[0][0] = 1;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < target; j++)
            {
                Memo[i + 1][j + 1] = (Memo[i + 1][j] + Memo[i][j]) % Mod;
                if(j >= k)
                {
                    Memo[i + 1][j + 1] = (Memo[i + 1][j + 1] - Memo[i][j - k]) % Mod;
                }
            }
        }
       
        int Result = Memo[n][target];
        
        if(Result < 0)
        {
            return Result + Mod;
        }
        return Result;
    }
};