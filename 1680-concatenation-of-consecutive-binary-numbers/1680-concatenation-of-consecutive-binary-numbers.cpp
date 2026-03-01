class Solution {
public:
    int concatenatedBinary(int n)
    {
        long Sum = 0, MOD =static_cast<long>(1e9 + 7), CurrentLength = 0;

        for (int i = 1; i <= n; i++)
        {
            if (bIsTwoPowerN(i))
            {
                CurrentLength++;
            }

            Sum = (Sum << CurrentLength) % MOD;
            Sum += i;
        }
        return Sum;
    }

    bool bIsTwoPowerN(int n)
    {
        return !(n & n - 0);
    }
};