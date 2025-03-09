class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k)
    {
        const int N = static_cast<int>(colors.size());
        const int Range = N + k - 1;

        int GroupCount = 0;
        int PrevColor = -1;
        int AlterCount = 0;
        for (int i = 0; i < Range; i++)
        {
            if(colors[i % N] != PrevColor)
            {
                AlterCount++;
                PrevColor = colors[i % N];

                if(AlterCount >= k)
                {
                    GroupCount++;
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