class Solution {
    const int NotExist = -1;
public:
    int search(vector<int>& nums, int target)
    {
        int Left = 0, Right = static_cast<int>(nums.size()) - 1;
        
        while(Left <= Right)
        {
            int Middle = (Left + Right) / 2;
            
            if(nums[Middle] == target)
            {
                return Middle;
            }
            
            if(nums[Middle] >= nums[Left])
            {
                if(nums[Middle] > target && nums[Left] <= target)
                {
                    Right = Middle - 1;
                }
                else
                {
                    Left = Middle + 1;
                }
            }
            else
            {
                if(nums[Middle] < target && nums[Right] >= target)
                {
                    Left = Middle + 1;
                }
                else
                {
                    Right = Middle - 1;
                }
            }
        }
        
        return NotExist;
    }
};