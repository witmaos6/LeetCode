class Solution {
public:
    int largestCombination(vector<int>& candidates)
    {
        array<int, 24> BitCounts{};

        for(int Num : candidates)
        {
            int Bit = 0;
            
            while(Num > 0)
            {
                BitCounts[Bit] += (Num & 1);
                ++Bit;
                Num >>= 1;
            }
        }
        
        return *max_element(BitCounts.begin(), BitCounts.end());
    }
};