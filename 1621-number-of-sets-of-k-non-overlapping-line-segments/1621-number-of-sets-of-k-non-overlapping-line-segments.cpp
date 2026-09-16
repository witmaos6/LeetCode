class Solution {
    const int Mod = 1e9 + 7;
public:
    int numberOfSets(int n, int k)
    {
        int M = 2 * k;
        long Numer = 1;
        long Denomi = 1;

        for(int i = 1; i <= M; i++)
        {
            Numer = (Numer * (n + k - i)) % Mod;

            Denomi = (Denomi * i) % Mod;
        }

        return static_cast<int>(Numer * Pow(Denomi, Mod - 2) % Mod);
    }

private:
    long Pow(long A, long E)
    {
        long Result = 1;
        while(E > 0)
        {
            if((E & 1) != 0)
            {
                Result = (Result * A) % Mod;
            }
            A = (A * A) % Mod;
            E >>= 1;
        }
        return Result;
    }
};