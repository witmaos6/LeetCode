class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r)
    {
        const int N = nums.size();
        int Min = INT_MAX;
        for(int i = 0; i <= N - l; i++)
        {
            int Sum = 0;
            for(int j = i; j < i + l - 1; j++)
            {
                Sum += nums[j];
            }

            int Range = min(i + r, N);
            for(int j = i + l - 1; j < Range; j++)
            {
                Sum += nums[j];
                if(Sum > 0)
                    Min = min(Min, Sum);
            }
        }
        return Min == INT_MAX ? -1 : Min;
    }
};