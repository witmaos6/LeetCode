class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k)
    {
        const int N = static_cast<int>(colors.size());

        int GroupCount = 0;
        int PrevColor = -1;
        int AlterCount = 0;
        for (int i = 0; i < N + k - 1; i++)
        {
            if(colors[i % N] != PrevColor)
            {
                AlterCount++;
                PrevColor = colors[i % N];

                if(AlterCount == k)
                {
                    GroupCount++;
                    AlterCount--;
                }
            }
            else
            {
                AlterCount = 1;
            }
        }
        return GroupCount;
    }
};