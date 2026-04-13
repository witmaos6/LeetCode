class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start)
    {
        const int N = nums.size();

        int Result = INT_MAX;
        for(int i = 0; i < N; i++)
        {
            if(nums[i] == target)
            {
                Result = min(Result, abs(i - start));
            }
        }
        return Result;
    }
};