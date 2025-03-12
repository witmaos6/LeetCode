class Solution {
public:
    int maximumCount(vector<int>& nums)
    {
        int FirstZeroIndex = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int LastZeroIndex = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int Pos = static_cast<int>(nums.size()) - LastZeroIndex;

        return max(FirstZeroIndex, Pos);
    }
};