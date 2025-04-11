class Solution {
public:
    int countSymmetricIntegers(int low, int high)
    {
        int Count = 0;
        for(int Num = max(10, low); Num <= high; Num++)
        {
            string StrNum = to_string(Num);
            int Length = static_cast<int>(StrNum.size());

            if((Length & 1) == 1)
            {
                if(Num < 10)
                {
                    Num = 9;
                }
                else if(Num < 1000)
                {
                    Num = 999;
                }
                continue;
            }
        
            int LeftSum = 0;
            int RightSum = 0;
            int Half = Length / 2;
            for(int i = 0; i < Half; i++)
            {
                LeftSum += StrNum[i];
            }
            for(int i = Half; i < Length; i++)
            {
                RightSum += StrNum[i];
            }
            if(LeftSum == RightSum)
            {
                Count++;
            }
        }

        return Count;
    }
};