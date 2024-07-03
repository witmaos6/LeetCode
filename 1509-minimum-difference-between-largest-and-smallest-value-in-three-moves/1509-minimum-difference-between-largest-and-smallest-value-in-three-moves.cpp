class Solution {
public:
    int minDifference(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        if(N <= 4)
        {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int Left = 0, Right = N - 4;
        int Result = nums[Right] - nums[Left];
        
        for(int i = 0; i < 3; i++)
        {   
            Right++;
            Left++;
            int CurrDiffer = nums[Right] - nums[Left];
            Result = min(Result, CurrDiffer);
        }
        
        return Result;
    }
};