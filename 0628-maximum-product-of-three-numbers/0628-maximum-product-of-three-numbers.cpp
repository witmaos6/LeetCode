class Solution {
public:
    int maximumProduct(vector<int>& nums)
    {
        ranges::sort(nums);
        
        const int N = nums.size();
        return max(nums.back() * nums[N - 2] * nums[N - 3], nums.back() * nums.front() * nums[1]);
    }
};