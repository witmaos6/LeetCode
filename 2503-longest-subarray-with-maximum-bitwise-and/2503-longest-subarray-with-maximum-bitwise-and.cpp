class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int MaxBitwiseAnd = *max_element(nums.begin(),nums.end());
        int MaxCount = 1;
        int Count = 1;
        for(int i = 1; i < N; i++)
        {
            if(nums[i] == nums[i - 1] && nums[i] == MaxBitwiseAnd)
            {
                Count++;
            }
            else
            {
                Count = 1;
            }
            MaxCount = max(MaxCount, Count);
        }
        return MaxCount;
    }
};