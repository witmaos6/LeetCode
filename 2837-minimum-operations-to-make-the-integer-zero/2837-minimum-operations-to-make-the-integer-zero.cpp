class Solution {
public:
    int makeTheIntegerZero(int num1, int num2)
    {
        if(num2 == 0)
            return popcount(unsigned(num1));

        long long X = num1;
        for(int i = 1; i < 61; i++)
        {
            X -= num2;
            if(X < i)
                return -1;
            if(X >= 0 && i >= popcount((unsigned long long)(X)))
                return i;
        }
        return -1;
    }
};