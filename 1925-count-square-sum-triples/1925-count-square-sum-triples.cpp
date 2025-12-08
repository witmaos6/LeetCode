class Solution {
public:
    int countTriples(int n)
    {
        int Count = 0;
        int Sqrt = sqrt(n);
        for(int u = 2; u <= Sqrt; u++)
        {
            for(int v = 1; v < u; v++)
            {
                if(~(u - v) & 1 || gcd(u, v) != 1)
                    continue;

                int C = u * u + v * v;
                if(C > n)
                    continue;
                
                Count += 2 * (n / C);
            }
        }
        return Count;
    }
};