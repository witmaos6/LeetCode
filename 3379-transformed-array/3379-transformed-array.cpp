class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Result(N);

        for(int i = 0; i < N; i++)
        {
            if(nums[i] == 0)
            {
                Result[i] = nums[i];
            }
            else
            {
                int Index = ((i + nums[i]) % N + N) % N;
                Result[i] = nums[Index];
            }
        }
        return Result;
    }
};