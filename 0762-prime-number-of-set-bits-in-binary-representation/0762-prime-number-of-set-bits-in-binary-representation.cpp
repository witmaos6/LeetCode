class Solution {
public:
    int countPrimeSetBits(int left, int right)
    {
        int Result = 0;
        for(int Num = left; Num <= right; Num++)
        {
            int Count = CountOneBit(Num);

            if(Count != 1 && IsPrime(Count))
            {
                Result++;
            }
        }
        return Result;
    }

private:
    int CountOneBit(int Num)
    {
        int Count = 0;
        while(Num > 0)
        {
            Count += (Num & 1);
            Num >>= 1;
        }
        return Count;
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