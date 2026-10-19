class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        vector<int> Result;

        int Begin = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int End = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        for(int i = Begin; i < End; i++)
        {
            Result.push_back(i);
        }
        return Result;
    }
};