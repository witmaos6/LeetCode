class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a) < abs(b);
        });

        const int N = nums.size();
        long long Result = 0;

        for(int i = 0; i < N / 2; i++)
        {
            Result -= nums[i] * nums[i];
        }
        for(int i = N / 2; i < N; i++)
        {
            Result += nums[i] * nums[i];
        }

        return Result;
    }
};