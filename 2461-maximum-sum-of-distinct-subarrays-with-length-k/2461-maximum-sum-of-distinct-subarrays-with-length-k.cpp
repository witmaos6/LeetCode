class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k)
    {
        vector<bool> Table(1e5 + 1, false);
        
        const int N = static_cast<int>(nums.size());
        long long MaxSubSum = 0;
        long long SubSum = 0;
        
        int Left = 0;
        int Size = 0;
        for(int Right = 0; Right < N; ++Right)
        {
            while(Table[nums[Right]] == true || Size >= k)
            {
                Table[nums[Left]] = false;
                SubSum -= nums[Left];
                ++Left;
                --Size;
            }
            
            Table[nums[Right]] = true;
            SubSum += nums[Right];
            ++Size;
            
            if(Size == k)
            {
                MaxSubSum = max(MaxSubSum, SubSum);
            }
        }
        
        return MaxSubSum;
    }
};