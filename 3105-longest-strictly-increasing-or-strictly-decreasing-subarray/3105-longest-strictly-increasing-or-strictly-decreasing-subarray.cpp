class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums)
    {
        const int N = nums.size();
        int IncreasingCount = 1;
        int DecreasingCount = 1;
        int MaxCount = 1;
        for(int i = 1; i < N; i++)
        {
            if(nums[i - 1] < nums[i])
            {
                DecreasingCount = 1;

                IncreasingCount++;
                MaxCount = max(MaxCount, IncreasingCount);
            }
            else if(nums[i - 1] > nums[i])
            {
                IncreasingCount = 1;

                DecreasingCount++;
                MaxCount = max(MaxCount, DecreasingCount);
            }
            else
            {
                IncreasingCount = 1;
                DecreasingCount = 1;
            }
        }
        
        return MaxCount;
    }
};