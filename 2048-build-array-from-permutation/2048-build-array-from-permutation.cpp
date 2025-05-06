class Solution {
public:
    vector<int> buildArray(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        for(int i = 0; i < N; i++)
        {
            nums[i] += (1024 * (nums[nums[i]] % 1024));
        }

        for(int i = 0; i < N; i++)
        {
            nums[i] /= 1024;
        }
        return nums;
    }
};