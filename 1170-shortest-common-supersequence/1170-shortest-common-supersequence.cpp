class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        const int Str1Size = static_cast<int>(str1.size());
        const int Str2Size = static_cast<int>(str2.size());

        vector<vector<int>> Memo(Str1Size + 1, vector<int>(Str2Size + 1));
        for(int i = 1; i <= Str1Size; i++)
        {
            for(int j = 1; j <= Str2Size; j++)
            {
                if(str1[i - 1] == str2[j - 1])
                {
                    Memo[i][j] = 1 + Memo[i - 1][j - 1];
                }
                else
                {
                    Memo[i][j] = max(Memo[i - 1][j], Memo[i][j - 1]);
                }
            }
        }

        int i = Str1Size;
        int j = Str2Size;
        string Result;
        while(i > 0 && j > 0)
        {
            if(str1[i - 1] == str2[j - 1])
            {
                Result += str1[i - 1];
                i--;
                j--;
            }
            else if(Memo[i - 1][j] > Memo[i][j - 1])
            {
                Result += str1[i - 1];
                i--;
            }
            else
            {
                Result += str2[j - 1];
                j--;
            }
        }
        while(i > 0)
        {
            Result += str1[i - 1];
            i--;
        }
        while(j > 0)
        {
            Result += str2[j - 1];
            j--;
        }

        reverse(Result.begin(), Result.end());
        return Result;
    }
};