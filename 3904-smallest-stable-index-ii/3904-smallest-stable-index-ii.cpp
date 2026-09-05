class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k)
    {
        const int N = nums.size();

        vector<int> Mins(N, INT_MAX);
        Mins[N - 1] = nums[N - 1];
        for(int i = N - 2; i >= 0; i--)
        {
            Mins[i] = min(Mins[i + 1], nums[i]);
        }

        int Max = nums[0];
        for(int i = 0; i < N; i++)
        {
            Max = max(Max, nums[i]);
            if(Max - Mins[i] <= k)
                return i;
        }
        return -1;
    }
};