class Solution {
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        const int N = static_cast<int>(colors.size());
        int MinTime = 0;
        int i = 0;
        
        while(i < N)
        {
            int MaxTime = 0;
            char CurrColor = colors[i];
            
            while(CurrColor == colors[i])
            {
                MinTime += neededTime[i];
                MaxTime = max(MaxTime, neededTime[i]);
                i++;
            }
            
            if(MaxTime != 0)
            {
                MinTime -= MaxTime;
            }
            else
            {
                i++;
            }
        }
        
        return MinTime;
    }
};