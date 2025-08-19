class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        nums.push_back(1);
        const int N = static_cast<int>(nums.size());
        long long Count = 0;
        long long Result = 0;
        for(int i = 0; i < N; i++)
        {
            if(nums[i] == 0)
            {
                Count++;
            }
            else
            {
                Result += (Count * (Count + 1) >> 1);
                Count = 0;
            }
        }
        return Result;
    }
};