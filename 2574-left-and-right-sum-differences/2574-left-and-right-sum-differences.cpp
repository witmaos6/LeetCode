class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums)
    {
        const int N = nums.size();
        int LeftSum = 0;
        int RightSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> Result(N);

        for(int i = 0; i < N; i++)
        {
            RightSum -= nums[i];
            Result[i] = abs(LeftSum - RightSum);
            LeftSum += nums[i];
        }
        return Result;
    }
};