class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k)
    {
        const int N = nums.size();
        
        vector<int> Maxs(N);
        Maxs[0] = nums[0];
        for(int i = 1; i < N; i++)
        {
            Maxs[i] = max(Maxs[i - 1], nums[i]);
        }

        vector<int> Mins(N);
        Mins[N - 1] = nums[N - 1];
        for(int i = N - 2; i >= 0; i--)
        {
            Mins[i] = min(Mins[i + 1], nums[i]);
        }

        for(int i = 0; i < N; i++)
        {
            if(Maxs[i] - Mins[i] <= k)
            {
                return i;
            }
        }

        return -1;
    }
};