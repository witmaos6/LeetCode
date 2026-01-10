class Solution {
public:
    int minimumDeleteSum(string s1, string s2)
    {
        const int S1Size = static_cast<int>(s1.size());
        const int S2Size = static_cast<int>(s2.size());
        
        vector<vector<int>> Memo(S1Size + 1, vector<int>(S2Size + 1));
        for(int i = 1; i <= S1Size; i++)
        {
            Memo[i][0] = Memo[i - 1][0] + s1[i - 1];
        }
        for(int i = 1; i <= S2Size; i++)
        {
            Memo[0][i] = Memo[0][i - 1] + s2[i - 1];
        }
        
        for(int i = 1; i <= S1Size; i++)
        {
            for(int j = 1; j <= S2Size; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                {
                    Memo[i][j] = Memo[i - 1][j - 1];
                }
                else
                {
                    int S1Temp = Memo[i - 1][j] + s1[i - 1];
                    int S2Temp = Memo[i][j - 1] + s2[j - 1];
                    Memo[i][j] = min(S1Temp, S2Temp);
                }
            }
        }
        
        return Memo[S1Size][S2Size];
    }
};