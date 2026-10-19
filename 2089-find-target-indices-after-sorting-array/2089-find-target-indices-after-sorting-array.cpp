class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        vector<int> Result;
        for(int i = 0; i < N; i++)
        {
            if(nums[i] == target)
            {
                Result.push_back(i);
            }
        }
        return Result;
    }
};