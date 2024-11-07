class Solution {
public:
    int largestCombination(vector<int>& candidates)
    {
        const int Max = 1e7;
        
        int MaxCount = 0;
        for(int i = 1; i < Max; i <<= 1)
        {
            int Count = 0;
            
            for(int& Num : candidates)
            {
                if(Num & i)
                {
                    ++Count;
                }
            }
            
            MaxCount = max(MaxCount, Count);
        }
        
        return MaxCount;
    }
};