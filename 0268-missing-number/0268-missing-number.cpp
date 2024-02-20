class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        
        int ZeroToNSum = (N * (N + 1)) / 2;
        int Sum = accumulate(nums.begin(), nums.end(), 0);
        
        return ZeroToNSum - Sum;
    }
};