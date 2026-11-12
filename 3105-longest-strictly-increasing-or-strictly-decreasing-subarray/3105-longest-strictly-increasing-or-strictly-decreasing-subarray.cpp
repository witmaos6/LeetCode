class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums)
    {
        const int N = nums.size();
        int Count = 1;
        int MaxCount = 1;
        for(int i = 1; i < N; i++)
        {
            if(nums[i - 1] < nums[i])
            {
                Count++;
                MaxCount = max(MaxCount, Count);
            }
            else
            {
                Count = 1;
            }
        }
        Count = 1;
        for(int i = 1; i < N; i++)
        {
            if(nums[i - 1] > nums[i])
            {
                Count++;
                MaxCount = max(MaxCount, Count);
            }
            else
            {
                Count = 1;
            }
        }
        return MaxCount;
    }
};