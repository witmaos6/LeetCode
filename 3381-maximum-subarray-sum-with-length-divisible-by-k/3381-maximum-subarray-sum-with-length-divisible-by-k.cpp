class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());

        vector<long long> Memo(k, LLONG_MAX / 2);
        long long Prefix = 0;
        long long Result = LLONG_MIN;
        Memo[k - 1] = 0;

        for(int i = 0; i < N; i++)
        {
            Prefix += nums[i];
            long long& KSum = Memo[i % k];
            Result = max(Result, Prefix - KSum);
            KSum = min(Prefix, KSum);
        }
        return Result;
    }
};