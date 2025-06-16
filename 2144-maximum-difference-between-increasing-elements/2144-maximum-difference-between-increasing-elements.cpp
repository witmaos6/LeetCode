class Solution {
public:
    int maximumDifference(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int Result = -1;
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                if(nums[i] < nums[j])
                {
                    Result = max(Result, (nums[j] - nums[i]));
                }
            }
        }
        return Result;
    }
};