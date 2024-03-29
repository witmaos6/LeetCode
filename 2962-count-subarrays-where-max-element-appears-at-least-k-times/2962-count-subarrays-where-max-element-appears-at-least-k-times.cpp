class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        long long MaxNum = *max_element(nums.begin(), nums.end());
        long long Count = 0;
        long long Left = 0;
        long long Result = 0;
        
        for(long long Right = 0; Right < N; Right++)
        {
            if(nums[Right] == MaxNum)
            {
                Count++;
            }
            
            while(Count >= k)
            {
                if(nums[Left] == MaxNum)
                {
                    Count--;
                }
                Left++;
                Result += N - Right;
            }    
        }

        return Result;
    }
};