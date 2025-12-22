class Solution {
public:
    int minDeletionSize(vector<string>& strs)
    {
        const int N = static_cast<int>(strs[0].size());
        const int M = static_cast<int>(strs.size());

        vector<int> Memo(N, 1);

        for(int i = 1; i < N; i++)
        {
            for(int j = 0; j < i; j++)
            {
                bool Flag = true;

                for(int R = 0; R < M; R++)
                {
                    if(strs[R][j] > strs[R][i])
                    {
                        Flag = false;
                        break;
                    }
                }

                if(Flag)
                {
                    Memo[i] = max(Memo[i], Memo[j] + 1);
                }
            }
        }

        int Max = 0;
        for(int& Num : Memo)
        {
            Max = max(Max, Num);
        }        
        return N - Max;
    }
};