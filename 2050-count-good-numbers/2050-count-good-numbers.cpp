class Solution {
    const int Mod = 1e9 + 7;
public:
    int countGoodNumbers(long long n)
    {
        long long NrOfEven = 5;
        long long NrOfPrime = 4;

        long long Even = (n + 1) / 2;
        long long Odd = n / 2;
        
        long long CountPrime = Power(NrOfPrime, Odd);
        long long CountEven = Power(NrOfEven, Even);

        return static_cast<int>(CountPrime * CountEven % Mod);
    }

    long long Power(long long Num, long long Power)
    {
        long long Result = 1;
        Num %= Mod;

        while(Power > 0)
        {
            if((Power & 1) == 1)
            {
                Result = (Result * Num) % Mod;
            }

            Num = (Num * Num) % Mod;
            Power /= 2;
        }

        return Result;
    }
};