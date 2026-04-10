class Solution {
public:
    int minimumDistance(vector<int>& nums)
    {
        const int N = nums.size();
        int Result = INT_MAX;

        for(int i = 0; i < N - 2; i++)
        {
            for(int j = i + 1; j < N - 1; j++)
            {
                for(int k = j + 1; k < N; k++)
                {
                    if(nums[i] == nums[j] && nums[j] == nums[k])
                    {
                        int Distance = abs(i - j) + abs(j - k) + abs(k - i);
                        Result = min(Result, Distance);
                    }
                }
            }
        }
        return (Result == INT_MAX) ? -1 : Result;
    }
};