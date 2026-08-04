class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums)
    {
        vector<int> Result;
        ranges::sort(nums);

        const int N = nums.size();
        for(int i = 1; i < N; i++)
        {
            for(int j = nums[i - 1] + 1; j < nums[i]; j++)
            {
                Result.push_back(j);
            }
        }
        return Result;
    }
};