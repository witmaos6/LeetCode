class Solution {
    const int Mod = pow(10, 9) + 7;
public:
    int countOrders(int n)
    {
        long long Count = 1;
        
        for(int i = 2; i <= n; i++)
        {
            long long Temp = (2 * i - 1);
            Count *= Temp * i;
            Count %= Mod;
        }
        
        return static_cast<int>(Count);
    }
};