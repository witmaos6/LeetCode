class Solution {
public:
    int differenceOfSums(int n, int m)
    {
        if(m > n)
        {
            return (n * (n + 1)) / 2;
        }
        int Sum = 0;
        for(int i = 1; i <= n; i++)
        {
            if(i % m == 0)
            {
                Sum -= i;
            }
            else
            {
                Sum += i;
            }
        }

        return Sum;
    }
};