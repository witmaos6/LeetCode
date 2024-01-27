class Solution {
public:
    int kInversePairs(int n, int k)
    {
        const int Mod = 1e9 + 7;
        vector<vector<int>> Memo(n + 1, vector<int>(k + 1));
        Memo[0][0] = 1;
        
        for(int i = 1; i <= n; i++)
        {
            long long Value = 0;
            
            for(int j = 0; j <= k; j++)
            {
                Value += Memo[i - 1][j];
                
                if(j >= i)
                {
                    Value -= Memo[i - 1][j - i];
                }
                
                long long Temp = Value + Memo[i][j];
                Memo[i][j] = static_cast<int>(Temp % Mod);
            }
        }
        
        return Memo[n][k];
    }
};