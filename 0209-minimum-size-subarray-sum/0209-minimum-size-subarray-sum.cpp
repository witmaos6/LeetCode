class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int PrefixSum = nums[0];
        
        int MinSize = INT_MAX;
        int Left = 0, Right = 0;
        int CurrSize = 1;
        
        while(Right < N)
        {
            if(PrefixSum >= target)
            {
                MinSize = min(MinSize, CurrSize);
                PrefixSum -= nums[Left];
                Left++;
                CurrSize--;
            }
            else
            {
                if(Right < N - 1)
                {
                    Right++;
                }
                else
                {
                    break;
                }
                
                PrefixSum += nums[Right];
                CurrSize++;
            }
        }
        
        if(MinSize == INT_MAX)
        {
            return 0;
        }
        return MinSize;
    }
};