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
        for(int i = N - 1; i > 0; --i)
        {
            int MaxValue = Digits[i];
            int MaxIndex = -1;
            for(int j = i - 1; j >= 0; --j)
            {
                if(MaxValue < Digits[j])
                {
                    MaxValue = Digits[j];
                    MaxIndex = j;
                }
                else if(MaxValue == Digits[j] && MaxValue != Digits[i])
                {
                    MaxIndex = j;
                }
            }
            
            if(MaxIndex != -1)
            {
                swap(Digits[i], Digits[MaxIndex]);
                break;
            }
        }
        
        int Result = 0;
        for(int i = 0; i < N; ++i)
        {
            Result += (Digits[i] * pow(10, i));
        }
        
        return Result;
    }
};