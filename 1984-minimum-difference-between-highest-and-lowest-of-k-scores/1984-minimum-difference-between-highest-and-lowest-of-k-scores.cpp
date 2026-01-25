class Solution {
public:
    int minimumDifference(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        const int N = static_cast<int>(nums.size());
        int Range = N - k + 1;
        int Result = INT_MAX;

        for(int i = 0; i < Range; i++)
        {
            int Diff = nums[i + k - 1] - nums[i];
            Result = min(Result, Diff);
        }
        return Result;
    }
};