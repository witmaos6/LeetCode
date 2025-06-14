class Solution {
public:
    int minMaxDifference(int num)
    {
        vector<int> Digits(9, -1);
        int Index = 8;
        while(num > 0)
        {
            Digits[Index] = (num % 10);
            num /= 10;
            Index--;
        }

        int RemapNum = -1;
        int RemapMinNum = -1;
        for(int i = 0; i < 9; i++)
        {
            if(Digits[i] != -1 && Digits[i] != 9 && RemapNum == -1)
            {
                RemapNum = Digits[i];
            }
            if(Digits[i] != -1 && RemapMinNum == -1)
            {
                RemapMinNum = Digits[i];
            }
        }

        int MaxNum = 0;
        int MinNum = 0;
        int Multi = 1;
        for(int i = 8; i >= 0; i--)
        {
            if(Digits[i] == -1)
            {
                break;
            }
            int MaxMultiNum = (Digits[i] == RemapNum) ? 9 : Digits[i];
            MaxNum += (MaxMultiNum * Multi);

            int MinMultiNum = (Digits[i] == RemapMinNum) ? 0 : Digits[i];
            MinNum += (MinMultiNum * Multi);

            Multi *= 10;
        }

        return MaxNum - MinNum;
    }
};