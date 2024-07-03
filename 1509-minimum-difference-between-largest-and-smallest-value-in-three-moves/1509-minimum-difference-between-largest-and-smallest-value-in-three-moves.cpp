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
        int Left = -1, Right = N - 5;
        int Result = INT_MAX;
        
        for(int i = 0; i < 4; i++)
        {
            Right++;
            Left++;
            
            int CurrDiffer = nums[Right] - nums[Left];
            Result = min(Result, CurrDiffer);
        }
        
        return Result;
    }
};