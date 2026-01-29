class Solution {
    const int LOWER_CHAR = 26;
    const long long MEMO_DEFAULT = 1e9;
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost)
    {
        const int N = static_cast<int>(original.size());
        vector<vector<long long>> Memo(LOWER_CHAR, vector<long long>(LOWER_CHAR, MEMO_DEFAULT));
        
        for(int i = 0; i < LOWER_CHAR; i++)
        {
            Memo[i][i] = 0;
        }
        for(int i = 0; i < N; i++)
        {
            long long Cost = static_cast<long long>(cost[i]);
            Memo[original[i] - 'a'][changed[i] - 'a'] = min(Memo[original[i] - 'a'][changed[i] - 'a'], Cost);
        }
        
         for (int k = 0; k < LOWER_CHAR; k++)
         {
            for (int i = 0; i < LOWER_CHAR; i++)
            {
                if (Memo[i][k] < MEMO_DEFAULT)
                {
                    for (int j = 0; j < LOWER_CHAR; j++)
                    {
                        if (Memo[k][j] < MEMO_DEFAULT)
                        {
                            Memo[i][j] = min(Memo[i][j], Memo[i][k] + Memo[k][j]);
                        }
                    }
                }
            }
        }
        
        const int M = static_cast<int>(source.size());
        long long Result = 0;
        for (size_t i = 0; i < M; i++)
        {
            int SourceChar = source[i] - 'a';
            int TargetChar = target[i] - 'a';
            
            if (SourceChar != TargetChar)
            {
                if (Memo[SourceChar][TargetChar] == MEMO_DEFAULT)
                {
                    return -1;
                }
                Result += Memo[SourceChar][TargetChar];
            }
        }
        
        return Result;
    }
};