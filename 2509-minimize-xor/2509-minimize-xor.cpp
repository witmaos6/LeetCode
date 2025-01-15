class Solution {
public:
    int minimizeXor(int num1, int num2)
    {
        int Num2BitCount = GetBitCount(num2);
        array<int, 32> Bitset = GetBitSet(num1);

        array<int, 32> ResultBitset;
        for(int i = 0; i < 32; i++)
        {
            if(Bitset[i] == 1)
            {
                Num2BitCount--;
                ResultBitset[i] = 1;

                if(Num2BitCount == 0)
                    break;
            }
        }
        if(Num2BitCount > 0)
        {
            for(int i = 31; i >= 0; i--)
            {
                if(ResultBitset[i] == 0)
                {
                    ResultBitset[i] = 1;
                    Num2BitCount--;
                    if(Num2BitCount == 0)
                        break;
                }
            }
        }

        int Result = 0;
        int Exponent = 0;
        for(int i = 31; i >= 0; i--)
        {
            if(ResultBitset[i] == 1)
            {
                long long Multiple = pow(2, Exponent);
                Result += (ResultBitset[i] * Multiple);
            }
            Exponent++;
        }

        return Result;
    }

private:
    int GetBitCount(int Num)
    {
        int Count = 0;
        while(Num > 0)
        {
            if((Num % 2) == 1)
            {
                Count++;
            }
            Num /= 2;
        }
        return Count;
    }

    array<int, 32> GetBitSet(int Num)
    {
        array<int, 32> Bitset;
        int Index = 0;

        while(Num > 0)
        {
            Bitset[Index] = (Num % 2);
            Index++;
            Num /= 2;
        }
        reverse(Bitset.begin(), Bitset.end());
        return Bitset;
    }
};