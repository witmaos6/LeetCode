class Solution {
public:
    int differenceOfSums(int n, int m)
    {
        if(m > n)
        {
            return (n * (n + 1)) / 2;
        }
        int Sum1 = 0;
        int Sum2 = 0;
        for(int i = 1; i <= n; i++)
        {
            if(i % m == 0)
            {
                Sum2 += i;
            }
            else
            {
                Sum1 += i;
            }
        }

        return Sum1 - Sum2;
    }
};