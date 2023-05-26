class Solution {
    vector<int> SuffixSum;
    vector<vector<int>> Memo;
    int N = 0;
public:
    int stoneGameII(vector<int>& piles)
    {
        N = static_cast<int>(piles.size());
        
        SuffixSum.resize(N);
        SuffixSum[N - 1] = piles[N - 1];
        for(int i = N - 2; i >= 0; i--)
        {
            SuffixSum[i] = SuffixSum[i + 1] + piles[i];
        }
        
        Memo.resize(N, vector<int>(N));
        return DP(piles, 0, 1);
    }
    
private:
    int DP(vector<int>& Piles, int Index, int M)
    {
        if(Index == N)
            return 0;
        
        if(2 * M + Index >= N)
        {
            return SuffixSum[Index];
        }
        
        if(Memo[Index][M] > 0)
        {
            return Memo[Index][M];
        }
        
        int Result = 0;
        
        for(int X = 1; X <= 2 * M; X++)
        {
            int Turn = SuffixSum[Index] - DP(Piles, Index + X, max(M, X));
            Result = max(Result, Turn);
        }
        Memo[Index][M] = Result;
        
        return Result;
    }
};