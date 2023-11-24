class Solution {
public:
    int maxCoins(vector<int>& piles)
    {
        const int N = static_cast<int>(piles.size());
        sort(piles.begin(), piles.end());
        
        int Result = 0;
        for(int i = N / 3; i < N; i += 2)
        {
            Result += piles[i];
        }
        return Result;
    }
};