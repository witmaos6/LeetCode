class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int Result = INT_MAX;
        int Count = 0;
        for(int i = 0; i < N; i++)
        {
            Count += (nums[i] == 1);
        }

        if(Count)
            return N - Count;

        for(int i = 0; i < N; i++)
        {
            int GCD = nums[i];
            for(int j = i + 1; j < N; j++)
            {
                GCD = __gcd(GCD, nums[j]);

                if(GCD == 1)
                {
                    Result = min(Result, j - i + N - 1);
                    break;
                }
            }
        }
        return (Result == INT_MAX) ? -1 : Result;
    }
};