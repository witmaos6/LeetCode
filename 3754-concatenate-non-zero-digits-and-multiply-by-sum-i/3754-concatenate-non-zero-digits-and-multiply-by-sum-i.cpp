class Solution {
public:
    long long sumAndMultiply(int n)
    {
        long long Sum = 0;
        long long X = 0;
        long long Digit = 1;

        while(n > 0)
        {
            int Num = n % 10;
            n /= 10;

            if(Num == 0)
                continue;

            Sum += Num;
            X += Digit * Num;
            Digit *= 10;
        }
        return Sum * X;
    }
};