class Solution {
public:
    int rob(vector<int>& nums)
    {
        const size_t N = nums.size();
        vector<int> Memo(N + 1);
        Memo[1] = nums[0];
        
        for(size_t i = 2; i <= N; i++)
        {
            Memo[i] = max(Memo[i - 1], Memo[i - 2] + nums[i - 1]);
        }
        
        return Memo.back();
    }
};