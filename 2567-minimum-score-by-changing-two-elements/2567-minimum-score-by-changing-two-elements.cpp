class Solution {
    // 8 28 42 58 75
    // 33, 34
public:
    int minimizeSum(vector<int>& nums)
    {
        const int N = nums.size();
        if(N == 3)
            return 0;

        ranges::sort(nums);

        int Case1 = nums[N - 1] - nums[2];
        int Case2 = nums[N - 3] - nums[0];
        int Case3 = nums[N - 2] - nums[1];
        return min({Case1, Case2, Case3});
    }
};