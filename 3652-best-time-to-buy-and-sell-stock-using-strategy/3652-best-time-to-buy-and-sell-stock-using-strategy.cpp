class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k)
    {
        const int N = static_cast<int>(prices.size());
        const int Half = k / 2;
        vector<long long> PrefixSum(1e5 + 1);

        for(int i = 0; i < N; i++)
        {
            PrefixSum[i + 1] = PrefixSum[i] + 1LL * strategy[i] * prices[i];
        }

        long long WindowSum = reduce(prices.begin() + Half, prices.begin() + k, 0LL);
        long long MaxProfit = max(PrefixSum[N], WindowSum + PrefixSum[N] - PrefixSum[k]);

        for(int Begin = 1; Begin + k <= N; Begin++)
        {
            WindowSum += prices[Begin + k - 1] - prices[Begin + Half - 1];
            MaxProfit = max(MaxProfit, WindowSum + PrefixSum[N] - PrefixSum[Begin + k] + PrefixSum[Begin]);
        }

        return MaxProfit;
    }
};