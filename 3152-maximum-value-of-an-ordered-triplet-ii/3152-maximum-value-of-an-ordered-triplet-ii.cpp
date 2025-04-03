class Solution {
public:
    long long maximumTripletValue(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());

        long long MaxI = nums[0];
        long long MaxIJ = 0;
        long long Result = 0;

        for(int i = 1; i < N - 1; i++)
        {
            MaxIJ = max(MaxIJ, MaxI - nums[i]);
            MaxI = max(MaxI, (long long)nums[i]);
            Result = max(Result, MaxIJ * nums[i + 1]);
        }

        return Result;
    }
};