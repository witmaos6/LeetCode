class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> Result(N / 3, vector<int>(3));
        
        for(int i = 0; i < N; i += 3)
        {
            if(nums[i + 2] - nums[i] <= k)
            {
                Result[i / 3][0] = nums[i];
                Result[i / 3][1] = nums[i + 1];
                Result[i / 3][2] = nums[i + 2];
            }
            else
            {
                return {};
            }
        }
        return Result;
    }
};