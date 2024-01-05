class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int LIS = 0;
        for(int Num : nums)
        {
            if(LIS == 0 || nums[LIS - 1] < Num)
            {
                nums[LIS] = Num;
                LIS++;
            }
            else
            {
                *lower_bound(nums.begin(), nums.begin() + LIS, Num) = Num;
            }
        }
        
        return LIS;
    }
};