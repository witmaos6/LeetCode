class Solution {
public:
    int integerBreak(int n)
    {
        if(n == 2 || n == 3)
        {
            return n - 1;
        }
        
        int Count3Sum = n / 3;
        int Remain = n % 3;
        
        if(Remain == 0)
        {
            return pow(3, Count3Sum);
        }
        else if(Remain == 1)
        {
            return pow(3, Count3Sum - 1) * 4;
        }
        return pow(3, Count3Sum) * 2;
    }
};