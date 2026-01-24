class Solution {
public:
    int minPairSum(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());
        int Result = INT_MIN;

        for(int i = 0; i < N / 2; i++)
        {
            int Sum = nums[i] + nums[N - i - 1];
            Result = max(Result, Sum);
        }
        return Result;
    }
};