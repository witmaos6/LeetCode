class Solution {
public:
    long long minEnd(int n, int x)
    {
        bitset<64> X(x);
        bitset<64> N(n - 1);
        bitset<64> Result = 0;
        
        int j = 0;
        for(int i=0; i < 56; ++i)
        {
            Result[i] = (X[i]) ? 1 : N[j++];
        }
        
        return Result.to_ullong();
    }
};