class Solution {
public:
    long long countCommas(long long n)
    {
        long long Thousand = 1000;
        array<long long, 6> Pows;
        for(int i = 0; i < 6; i++)
        {
            Pows[i] = pow(Thousand, i + 1);
        }

        long long K = 0;
        for(long long& Pow : Pows)
        {
            K += (n >= Pow);
        }

        return K * (n + 1) - (Pows[K] - 1000) / 999;
    }
};