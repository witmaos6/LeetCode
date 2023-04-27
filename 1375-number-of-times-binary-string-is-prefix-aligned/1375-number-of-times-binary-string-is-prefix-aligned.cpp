class Solution {
public:
    int numTimesAllBlue(vector<int>& flips)
    {
        int N = static_cast<int>(flips.size());
        int Count = 0;
        int RIndex = 0;
        
        for(int i = 0; i < N; i++)
        {
            RIndex = max(RIndex, flips[i]);
            
            if(RIndex == i + 1)
            {
                Count++;
            }
        }
        
        return Count;
    }
};