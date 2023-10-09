class Solution {
    vector<int> NotExist = {-1, -1};
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if(nums.empty())
        {
            return NotExist;
        }
        
        int TargetBegin = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int TargetEnd = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        if(TargetBegin > static_cast<int>(nums.size()) - 1 || nums[TargetBegin] != target)
        {
            return NotExist;
        }
        
        return {TargetBegin, TargetEnd - 1};
    }
};