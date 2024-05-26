class Solution {
public:
    int checkRecord(int n)
    {
        const int Mod = 1e9 + 7;
        
        vector<vector<int>> PrevMemo(2, vector<int>(3, 1));
        
        for(int i = 1; i <= n; i++)
        {
            vector<vector<int>> CurrMemo(2, vector<int>(3, 0));
            
            for(int A = 0; A < 2; A++)
            {
                for(int L = 0; L < 3; L++)
                {
                    CurrMemo[A][L] += PrevMemo[A][2];
                    CurrMemo[A][L] %= Mod;
                    
                    if(A > 0)
                    {
                        CurrMemo[A][L] += PrevMemo[A - 1][2];
                        CurrMemo[A][L] %= Mod;
                    }
                    if(L > 0)
                    {
                        CurrMemo[A][L] += PrevMemo[A][L - 1];
                        CurrMemo[A][L] %= Mod;
                    }
                }
            }
            
            PrevMemo = CurrMemo;
        }
        
        return PrevMemo[1][2];
    }
};