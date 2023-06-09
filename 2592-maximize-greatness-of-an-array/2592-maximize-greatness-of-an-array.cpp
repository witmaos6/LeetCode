class Solution {
public:
    int maximizeGreatness(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        
        int Result = 0;
        for(int& Num : nums)
        {
            if(Num > nums[Result])
            {
                Result++;
            }
        }
        
        return Result;
    }
};