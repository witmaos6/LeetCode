class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        
        vector<int> Sums(3);
        for(int i = 0; i < k; i++)
        {
            Sums[0] += nums[i];
            Sums[1] += nums[i + k];
            Sums[2] += nums[i + 2 * k];
        }

        vector<int> Max = {Sums[0], Sums[0] + Sums[1], Sums[0] + Sums[1] + Sums[2]};
        vector<int> Indices = {0, 0, k};
        vector<int> Result = {0, k, 2 * k};

        for(int i = 0; i <= N - 3 * k; i++)
        {
            if(i > 0)
            {
                Sums[0] = Sums[0] - nums[i - 1] + nums[i + k - 1];
                Sums[1] = Sums[1] - nums[i + k - 1] + nums[i + 2 * k - 1];
                Sums[2] = Sums[2] - nums[i + 2 * k - 1] + nums[i + 3 * k - 1];
            }

            if(Sums[0] > Max[0])
            {
                Max[0] = Sums[0];
                Indices[0] = i;
            }
            if(Max[0] + Sums[1] > Max[1])
            {
                Max[1] = Max[0] + Sums[1];
                Indices[1] = Indices[0];
                Indices[2] = i + k;
            }
            if(Max[1] + Sums[2] > Max[2])
            {
                Max[2] = Max[1] + Sums[2];
                Result = {Indices[1], Indices[2], i + 2 * k};
            }
        }

        return Result;
    }
};