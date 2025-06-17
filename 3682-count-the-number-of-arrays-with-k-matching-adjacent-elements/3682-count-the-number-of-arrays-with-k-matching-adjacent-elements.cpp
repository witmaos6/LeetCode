class Solution {
public:
    int countGoodArrays(int n, int m, int k)
    {
        const int Mod = 1e9 + 7;
        int D = n - 1;
        if(k > D)
            return 0;

        int R = k;
        if(R > D - R)
            R = D - R;
        
        long long C = 1;
        if(R > 0)
        {
            vector<int> Inv(R + 1);
            Inv[1] = 1;
            for(int i = 2; i <= R; i++)
            {
                long long Temp = Mod - Mod / i;
                Inv[i] = Temp * Inv[Mod % i] % Mod;
            }
            for(int i = 1; i <= R; i++)
            {
                C = C * (D - R + i) % Mod;
                C = C * Inv[i] % Mod;
            }
        }

        auto ModPow = [&](long long Base, int Num)
        {
            long long Result = 1;
            while(Num > 0)
            {
                if(Num & 1)
                {
                    Result = Result * Base % Mod;
                }
                Base = Base * Base % Mod;
                Num >>= 1;
            }
            return Result;
        };

        long long M = static_cast<long long>(m);

        return int((M * C % Mod) * ModPow(m - 1, D - k) % Mod);
    }
};