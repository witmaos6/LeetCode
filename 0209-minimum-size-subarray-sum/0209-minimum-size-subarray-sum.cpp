class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        
        int Left = 0, Right = 0;
        int Sum = nums[0], Length = INT_MAX;
        
        while(Left < N)
        {
            if(Sum < target)
            {
                Right++;
                if(Right >= N)
                {
                    break;
                }
                Sum += nums[Right];
            }
            else if(Sum >= target)
            {
                int CurrLength = Right - Left + 1;
                Length = min(Length, CurrLength);
                
                Sum -= nums[Left];
                Left++;
            }
        }
        
        if(Length == INT_MAX)
        {
            return 0;
        }
        return Length;
    }
};