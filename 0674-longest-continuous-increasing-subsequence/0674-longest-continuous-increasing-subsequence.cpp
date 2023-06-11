class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        
        int MaxLength = 1;
        int CurrLength = 1;
        
        for(int i = 1; i < N; i++)
        {
            if(nums[i] > nums[i - 1])
            {
                CurrLength++;
                MaxLength = max(MaxLength, CurrLength);
            }
            else
            {
                CurrLength = 1;
            }
        }
        
        return MaxLength;
    }
};