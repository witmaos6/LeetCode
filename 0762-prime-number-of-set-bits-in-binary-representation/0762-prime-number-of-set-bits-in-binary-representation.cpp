class Solution {
public:
    int countPrimeSetBits(int left, int right)
    {
        int Result = 0;
        for(int Num = left; Num <= right; Num++)
        {
            int Count = __builtin_popcount(Num);

            if(Count != 1 && IsPrime(Count))
            {
                Result++;
            }
        }
        return Result;
    }

    bool IsPrime(int Num)
    {
        for(int i = 2; i * i <= Num; i++)
        {
            if(Num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};