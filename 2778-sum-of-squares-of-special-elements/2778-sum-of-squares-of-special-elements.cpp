class Solution {
public:
    int sumOfSquares(vector<int>& nums)
    {
        const int N = nums.size();
        int Result = 0;
        for(int i = 1; i <= N; i++)
        {
            if(N % i == 0)
            {
                Result += (nums[i - 1] * nums[i - 1]);
            }
        }
        return Result;
    }
};