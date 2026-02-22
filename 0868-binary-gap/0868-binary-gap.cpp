class Solution {
public:
    int binaryGap(int n)
    {
        int PreIndex = -1;
        int Index = 0;
        int Result = 0;

        while(n > 0)
        {
            int Bit = (n & 1);
            if(Bit == 1)
            {
                if(PreIndex != -1)
                {
                    Result = max(Result, Index - PreIndex);
                }
                PreIndex = Index;
            }

            n >>= 1;
            Index++;
        }

        return Result;
    }
};