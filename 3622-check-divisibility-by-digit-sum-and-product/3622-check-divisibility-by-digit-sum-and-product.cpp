class Solution {
public:
    bool checkDivisibility(int n)
    {
        int Origin = n;
        int Sum = 0;
        int Product = 1;

        while(n > 0)
        {
            int Digit = n % 10;
            Sum += Digit;
            Product *= Digit;

            n /= 10;
        }
        return (Origin % (Sum + Product) == 0);
    }
};