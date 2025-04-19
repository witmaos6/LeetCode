class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        const int N = static_cast<int>(nums.size());
        long long Count = 0;
        
        for(int i = 0; i < N; ++i)
        {
            int FindLower = lower - nums[i];
            int FindUpper = upper - nums[i];
            
            auto Left = lower_bound(nums.begin() + i + 1, nums.end(), FindLower);
            auto Right = upper_bound(nums.begin() + i + 1, nums.end(), FindUpper);
            
            Count += (Right - Left);
        }
       
        return Count;
    }
};