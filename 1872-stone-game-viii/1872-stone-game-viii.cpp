class Solution {
public:
    int stoneGameVIII(vector<int>& stones)
    {
        const int N = stones.size();

        for(int i = 1; i < N; i++)
        {
            stones[i] += stones[i - 1];
        }

        int Best = stones[N - 1];

        for(int i = N - 2; i >= 1; i--)
        {
            Best = max(Best, stones[i] - Best);
        }

        return Best;
    }
};