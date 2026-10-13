class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a) > abs(b);
        });

        const int N = nums.size();
        long long Result = 0;
        int AddRange = N / 2 + (N & 1);
        for(int i = 0; i < AddRange; i++)
        {
            Result += nums[i] * nums[i];
        }

        for(int i = AddRange; i < N; i++)
        {
            Result -= nums[i] * nums[i];
        }

        return Result;
    }
};