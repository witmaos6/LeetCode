class Solution {
public:
    long long maximumTripletValue(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        long long Result = 0;
        long long MaxI = nums[0];
        long long MaxIJ = LLONG_MIN;

        for(int j = 1; j < N - 1; j++)
        {
            MaxIJ = max(MaxIJ, MaxI - nums[j]);
            MaxI = max(MaxI, (long long)nums[j]);
            Result = max(Result, MaxIJ * (long long)nums[j + 1]);
        }
        return Result;
    }
};