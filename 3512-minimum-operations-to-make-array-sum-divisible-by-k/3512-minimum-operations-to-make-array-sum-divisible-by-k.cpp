class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        int Sum = accumulate(nums.begin(), nums.end(), 0);
        return Sum % k;
    }
};