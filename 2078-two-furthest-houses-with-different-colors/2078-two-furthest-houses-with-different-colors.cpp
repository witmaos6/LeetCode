class Solution {
public:
    int maxDistance(vector<int>& colors)
    {
        const int N = colors.size();
        int MaxDist = 0;

        int i = 0, j = N - 1;

        while(colors[i] == colors[j])
        {
            i++;
        }
        MaxDist = max(MaxDist, j - i);

        i = 0;
        while(colors[i] == colors[j])
        {
            j--;
        }
        MaxDist = max(MaxDist, j - i);
        
        return MaxDist;
    }
};