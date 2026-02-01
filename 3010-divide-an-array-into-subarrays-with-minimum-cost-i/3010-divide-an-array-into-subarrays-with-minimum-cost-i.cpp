class Solution {
public:
    int minimumCost(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int Result = INT_MAX;
        
        for(int i = 1; i < N - 1; i++)
        {
            int Sum = INT_MAX;
            for(int j = i + 1; j < N; j++)
            {
                Sum = min(Sum, nums[i] + nums[j]);
            }
            Result = min(Result, nums[0] + Sum);
        }
        return Result;
    }
};