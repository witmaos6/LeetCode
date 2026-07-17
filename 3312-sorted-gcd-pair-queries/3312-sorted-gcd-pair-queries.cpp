class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries)
    {
        int Max = *max_element(nums.begin(), nums.end());
        vector<int> Freq(Max + 1);
        vector<long long> GCD(Max + 1);

        for(int& Num : nums)
        {
            Freq[Num]++;
        }

        for(int i = Max; i > 0; i--)
        {
            long long Sum = 0, Extra = 0;
            for(int j = i; j <= Max; j += i)
            {
                Sum += Freq[j];
                Extra += GCD[j];
            }
            GCD[i] = Sum * (Sum - 1) / 2 - Extra;
        }

        partial_sum(GCD.begin(), GCD.end(), GCD.begin());

        const int N = queries.size();
        vector<int> Result(N);
        for(int i = 0; i < N; i++)
        {
            Result[i] = upper_bound(GCD.begin(), GCD.end(), queries[i]) - GCD.begin();
        }

        return Result;
    }
};