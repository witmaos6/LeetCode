class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int Low = 0;
        int High = static_cast<int>(nums.size()) - 1;
        int Mid = 0;
        
        while(Mid <= High)
        {
            if(nums[Mid] == 0)
            {
                swap(nums[Low], nums[Mid]);
                Low++;
                Mid++;
            }
            else if(nums[Mid] == 1)
            {
                Mid++;
            }
            else if(nums[Mid] == 2)
            {
                swap(nums[Mid], nums[High]);
                High--;
            }
        }
    }
};