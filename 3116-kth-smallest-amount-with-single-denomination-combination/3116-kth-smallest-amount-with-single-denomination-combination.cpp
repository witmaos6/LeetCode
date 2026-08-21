class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k)
    {
        long long KK = k;
        long long L = 1, R = 1e11, Result = 0;
        while(L <= R)
        {
            long long M = L + (R - L) / 2;
            long long Count = 0;
            Count = Pie(coins, M);

            if(Count < KK)
            {
                L = M + 1;
            }
            else
            {
                Result = M;
                R = M - 1;
            }
        }
        return Result;
    }
private:
    long long Pie(vector<int>& Coins, long long X)
    {
        const int N = Coins.size();
        int NN = (1 << N);
        long long Count = 0;
        for(int i = 1; i < NN; i++)
        {
            long long LCMM = 1;
            for(int j = 0; j < N; j++)
            {
                if(i & (1 << j))
                {
                    LCMM = lcm(LCMM, Coins[j]);
                }
            }
            if(__builtin_popcount(i) & 1)
            {
                Count += X / LCMM;
            }
            else
            {
                Count -= X / LCMM;
            }
        }
        return Count;
    }
};