class Solution {
public:
    int maximumJumps(vector<int>& nums, int target)
    {
        const int N = nums.size();

        vector<int> Memo(N, -1);
        Memo[0] = 0;

        for(int i = 0; i < N; i++)
        {
            if(Memo[i] == -1)
                continue;
            
            for(int j = i + 1; j < N; j++)
            {
                long long Diff = 1LL * nums[j] - nums[i];

                if(abs(Diff) <= target)
                {
                    Memo[j] = max(Memo[j], Memo[i] + 1);
                }
            }
        }
        return Memo[N - 1];
    }
};