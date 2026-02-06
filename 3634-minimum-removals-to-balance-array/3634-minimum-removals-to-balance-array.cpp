class Solution {
public:
    int minRemoval(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        if(N == 1)
            return 0;

        sort(nums.begin(), nums.end());

        int Result = INT_MAX;
        for(int i = 0; i < N; i++)
        {
            long long Target = 1LL * nums[i] * k;
            if(Target >= INT_MAX)
            {
                Target = INT_MAX;
            }
            int Index = upper_bound(nums.begin() + i + 1, nums.end(), Target) - nums.begin();

            if(Index >= N)
            {
                Index--;
            }
            if(Target < nums[Index])
            {
                Index--;
            }
            int Remove = N - (Index + 1) + i;
            Result = min(Result, Remove);
        }
        return (Result == INT_MAX) ? 0 : Result;
    }
};