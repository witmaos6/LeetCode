class Solution {
public:
    int minDeletionSize(vector<string>& strs)
    {
        const int N = static_cast<int>(strs.size());
        const int M = static_cast<int>(strs[0].size());
        int Count = 0;

        for(int i = 0; i < M; i++)
        {
            for(int j = 1; j < N; j++)
            {
                if(strs[j][i] < strs[j - 1][i])
                {
                    Count++;
                    break;
                }
            }
        }
        return Count;
    }
};