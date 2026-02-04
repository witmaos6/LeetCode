class Solution {
    using Tuple = tuple<int, int, long long>;
public:
    long long maxSumTrionic(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        vector<long long> MaxEndingAt(N);

        for(int i = 0; i < N; i++)
        {
            MaxEndingAt[i] = nums[i];
            if(i > 0 && nums[i - 1] < nums[i])
            {
                if(MaxEndingAt[i - 1] > 0)
                {
                    MaxEndingAt[i] += MaxEndingAt[i - 1];
                }
            }
        }

        vector<long long> MaxStartingAt(N);
        for(int i = N - 1; i >= 0; i--)
        {
            MaxStartingAt[i] = nums[i];
            if(i < N - 1 && nums[i] < nums[i + 1])
            {
                if(MaxStartingAt[i + 1] > 0)
                {
                    MaxStartingAt[i] += MaxStartingAt[i + 1];
                }
            }
        }

        vector<Tuple> PQS = Decompose(nums);
        long long Result = LLONG_MIN;
        for(auto& [P, Q, Sum] : PQS)
        {
            if(P > 0 && nums[P - 1] < nums[P] && Q < N - 1 && nums[Q] < nums[Q + 1] && P < Q)
            {
                Result = max(Result, MaxEndingAt[P - 1] + Sum + MaxStartingAt[Q + 1]);
            }
        }
        return Result;
    }

    vector<Tuple> Decompose(vector<int>& Nums)
    {
        const int N = static_cast<int>(Nums.size());

        vector<Tuple> Sub;
        int L = 0;
        long long Sum = Nums[0];

        for(int i = 1; i < N; i++)
        {
            if(Nums[i - 1] <= Nums[i])
            {
                Sub.push_back({L, i - 1, Sum});
                L = i;
                Sum = 0;
            }
            Sum += Nums[i];
        }
        Sub.push_back({L, N - 1, Sum});
        return Sub;
    }
};