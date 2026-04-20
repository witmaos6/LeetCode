class Solution {
public:
    int maxDistance(vector<int>& colors)
    {
        const int N = colors.size();
        int MaxDist = 0;

        for(int i = 0; i < N; i++)
        {
            int CurrColor = colors[i];

            for(int j = 0; j < N; j++)
            {
                if(CurrColor != colors[j])
                {
                    MaxDist = max(MaxDist, abs(i - j));
                }
            }
        }
        return MaxDist;
    }
};