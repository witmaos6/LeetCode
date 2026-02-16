class Solution {
public:
    int reverseBits(int n)
    {
        int Result = 0;
        int i = 31;

        while(n > 0)
        {
            if((n & 1) == 1)
            {
                Result += pow(2, i);
            }
            i--;
            n >>= 1;
        }
        return Result;
    }
};