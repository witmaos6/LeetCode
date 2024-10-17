class Solution {
public:
    int maximumSwap(int num)
    {
        vector<int> Digits;
        while(num > 0)
        {
            int Digit = num % 10;
            Digits.push_back(Digit);
            num /= 10;
        }
        
        const int N = static_cast<int>(Digits.size());
        int MaxDigit = -1;
        int MaxIndex = -1;
        int LeftIndex = -1;
        int RightIndex = -1;
        for(int i = 0; i < N; ++i)
        {
            if(Digits[i] > MaxDigit){
                MaxDigit = Digits[i];
                MaxIndex = i;
                continue;
            }
            if(Digits[i] < MaxDigit)
            {
                LeftIndex = i;
                RightIndex = MaxIndex;
            }
        }

        if(LeftIndex != -1)
        {
            swap(Digits[LeftIndex], Digits[RightIndex]);
        }
        
        int Result = 0;
        for(int i = 0; i < N; ++i)
        {
            Result += (Digits[i] * pow(10, i));
        }
        
        return Result;
    }
};