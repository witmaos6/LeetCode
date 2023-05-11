class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Result(N);
        int L = 0, R = N - 1;
        
        for(int i = N - 1; i >= 0; i--)
        {
            if(abs(nums[L]) > abs(nums[R]))
            {
                Result[i] = nums[L] * nums[L];
                L++;
            }
            else
            {
                Result[i] = nums[R] * nums[R];
                R--;
            }
        }
        
        return Result;
    }
};