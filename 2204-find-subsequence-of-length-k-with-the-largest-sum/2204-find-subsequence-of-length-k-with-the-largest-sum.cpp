class Solution {
    using Pair = pair<int, int>;
public:
    vector<int> maxSubsequence(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());

        if(N == k)
            return nums;

        vector<Pair> Pairs(N);
        for(int i = 0; i < N; i++)
        {
            Pairs[i] = {nums[i], i};
        }

        sort(Pairs.begin(), Pairs.end());
        vector<Pair> Topk;
        Topk.reserve(k);
        for(int i = N - 1; i > N - k - 1; i--)
        {
            Topk.emplace_back(Pairs[i].second, Pairs[i].first);
        }
        sort(Topk.begin(), Topk.end());

        vector<int> Result;
        Result.reserve(k);
        for(int i = 0; i < k; i++)
        {
            Result.push_back(Topk[i].second);
        }
        return Result;
    }
};