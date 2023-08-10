class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int N = static_cast<int>(nums.size());
        
        int Left = 0, Right = N - 1;
        
        while(Left <= Right)
        {
            int Middle = (Right + Left) / 2;
            
            if(nums[Middle] == target)
            {
                return true;
            }
            
            if(nums[Left] == nums[Middle])
            {
                Left++;
                continue;
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
        
        return false;
    }
};