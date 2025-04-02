class Solution {
public:
    long long maximumTripletValue(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        long long Result = 0;
        for(int i = 0; i < N - 2; i++)
        {
            for(int j = i + 1; j < N - 1; j++)
            {
                for(int k = j + 1; k < N; k++)
                {
                    long long Temp = nums[i] - nums[j];
                    Temp *= nums[k];
                    Result = max(Result, Temp);
                }
            }
        }
        return Result;
    }
};