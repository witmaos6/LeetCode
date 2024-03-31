class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK)
    {
        const int N = static_cast<int>(nums.size());
        long long Result = 0;
        int LeftIndex = -1;
        int RightIndex = -1;
        int BadIndex = -1;
        
        for(int i = 0; i < N; i++)
        { 
            if(!(minK <= nums[i] && nums[i] <= maxK))
            {
                BadIndex = i;
            }
            if(nums[i] == minK)
            {
                LeftIndex = i;
            }
            if(nums[i] == maxK)
            {
                RightIndex = i;
            }
            
            Result += max(0, min(LeftIndex, RightIndex) - BadIndex);
        }
        
        return Result;
    }
};