class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int Left = 0;
        int Zeros = 0;
        int Result = 0;
        
        for(int Right = 0; Right < N; Right++)
        {
            if(nums[Right] == 0)
            {
                Zeros++;
            }
            while(Zeros > 1)
            {
                if(nums[Left] == 0)
                {
                    Zeros--;
                }
                Left++;
            }
            
            Result = max(Result, Right - Left + 1 - Zeros);
        }
        
        if(Result == N)
        {
            return Result - 1;
        }
        return Result;
    }
};