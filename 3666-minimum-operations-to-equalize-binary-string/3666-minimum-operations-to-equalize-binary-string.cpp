class Solution {
public:
    int minOperations(string s, int k)
    {
        const int N = static_cast<int>(s.size());
        int Zero = 0;
        for(int i = 0; i < N; i++)
        {
            Zero += ~s[i] & 1;
        }
        if(!Zero)
            return 0;

        if(N == k)
            return ((Zero == N) << 1) - 1;

        int Base = N - k;

        int Odd = max((Zero + k - 1) / k, (N - Zero + Base - 1) / Base);
        Odd += ~Odd & 1;

        int Even = max((Zero + k - 1) / k, (Zero + Base - 1) / Base);
        Even += Even & 1;

        int Result = INT_MAX;
        if((k & 1) == (Zero & 1))
        {
            Result = min(Result, Odd);
        }
        if(~Zero & 1)
        {
            Result = min(Result, Even);
        }

        return Result == INT_MAX ? -1: Result;
    }
};