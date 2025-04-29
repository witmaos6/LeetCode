class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k)
    {
        int MaxNum = *max_element(nums.begin(), nums.end());

        const int N = static_cast<int>(nums.size());
        int Left = 0;
        int MaxNumCount = 0;
        long long Result = 0;
        for(int i = 0; i < N; i++)
        {
            if(nums[i] == MaxNum)
            {
                MaxNumCount++;
            }
            while(MaxNumCount >= k)
            {
                if(nums[Left] == MaxNum)
                {
                    MaxNumCount--;
                }
                Left++;
                Result += N - i;
            }
        }
        return Result;
    }
};