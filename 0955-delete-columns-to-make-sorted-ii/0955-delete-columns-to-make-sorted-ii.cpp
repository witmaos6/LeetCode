class Solution {
public:
    int minDeletionSize(vector<string>& strs)
    {
        const int N = static_cast<int>(strs.size());
        const int M = static_cast<int>(strs[0].size());

        vector<bool> Resolved(N - 1);

        int Unresolved = N - 1;
        int Delete = 0;

        for(int Col = 0; Col < M && Unresolved > 0; Col++)
        {
            bool Bad = false;

            for(int i = 0; i < N - 1; i++)
            {
                if(!Resolved[i] && strs[i][Col] > strs[i + 1][Col])
                {
                    Bad = true;
                    break;
                }
            }

            if(Bad)
            {
                Delete++;
                continue;
            }

            for(int i = 0; i < N - 1; i++)
            {
                if(!Resolved[i] && strs[i][Col] < strs[i + 1][Col])
                {
                    Resolved[i] = true;
                    Unresolved--;
                }
            }
        }
        return Delete;
    }
};