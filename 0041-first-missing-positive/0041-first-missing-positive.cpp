class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        int ExistMinValue = 1;
        
        for(int& num : nums)
        {
            if(num > 0)
            {
                if(num == ExistMinValue)
                {
                    ExistMinValue++;
                }
                else
                {
                    break;
                }
            }
        }
        
        return ExistMinValue;
    }
};