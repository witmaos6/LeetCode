class Solution {
public:
    long long putMarbles(vector<int>& weights, int k)
    {
        if (k == 1)
        {
            return 0;
        }

        const int N = static_cast<int>(weights.size());
        vector<int> PairSums;
        for(int i = 0; i < N - 1; i++)
        {
            PairSums.push_back(weights[i] + weights[i + 1]);
        }
        sort(PairSums.begin(), PairSums.end());

        long long MinScore = accumulate(PairSums.begin(), PairSums.begin() + (k - 1), 0LL);
        long long MaxScore = accumulate(PairSums.end() - (k - 1), PairSums.end(), 0LL);

        return MaxScore - MinScore;
    }
};