class Solution {
public:
    vector<int> buildArray(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Nums(N);

        for(int i = 0; i < N; i++)
        {
            Nums[i] = nums[nums[i]];
        }
        return Nums;
    }
};