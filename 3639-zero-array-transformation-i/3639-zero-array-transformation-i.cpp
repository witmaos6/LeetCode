class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Memo(N + 1);

        for(vector<int>& Query : queries)
        {
            int L = Query[0];
            int R = Query[1];

            Memo[L] += -1;
            Memo[R + 1] += 1;
        }

        for(int i = 0; i < N; i++)
        {
            nums[i] += Memo[i];
            if(nums[i] > 0)
                return false;

            Memo[i + 1] += Memo[i];
        }

        return true;
    }
};