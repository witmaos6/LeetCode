class Solution {
public:
    int countTriples(int n)
    {
        int Count = 0;
        for(int a = 1; a <= n; a++)
        {
            for(int b = a + 1; b <= n; b++)
            {
                if((a * a) + (b * b) > n * n)
                {
                    break;
                }
                for(int c = b + 1; c <= n; c++)
                {
                    if((a * a) + (b * b) == c * c)
                    {
                        Count += 2;
                    }
                }
            }
        }
        return Count;
    }
};