class Solution {
public:
    int maxRotateFunction(vector<int>& nums)
    {
        const int N = nums.size();
        int PrefixSum = accumulate(nums.begin(), nums.end(), 0);

        int F = 0;
        for(int i = 0; i < N; i++)
        {
            F += (i * nums[i]);
        }

        int Result = F;

        for(int i = 0; i < N; i++)
        {
            int CurrF = F - PrefixSum + nums[i] * N;
            Result = max(Result, CurrF);
            F = CurrF;
        }
        return Result;
    }
};