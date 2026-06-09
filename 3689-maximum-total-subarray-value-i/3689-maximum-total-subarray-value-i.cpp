class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k)
    {
        int Max = *max_element(nums.begin(), nums.end());
        int Min = *min_element(nums.begin(), nums.end());

        long long Diff = Max - Min;
        return Diff * k;
    }
};