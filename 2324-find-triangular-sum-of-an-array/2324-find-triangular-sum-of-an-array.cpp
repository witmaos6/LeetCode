class Solution {
public:
    int triangularSum(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Memo(N - 1);
        for(int i = 0; i < N - 1; i++)
        {
            int M = static_cast<int>(Memo.size());
            for(int j = 0; j < M; j++)
            {
                Memo[j] = (nums[j] + nums[j + 1]) % 10;
            }
            nums = Memo;
            Memo.resize(nums.size() - 1);
        }
        return nums[0];
    }
};