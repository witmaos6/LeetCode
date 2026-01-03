class Solution {
public:
    int numOfWays(int n)
    {
        const int Mod = 1e9 + 7;
        long long A = 6, B = 6;
        for(int i = 2; i <= n; i++)
        {
            long long NewA = (2 * A + 2 * B) % Mod;
            long long NewB = (2 * A + 3 * B) % Mod;

            A = NewA;
            B = NewB;
        }
        return (A + B) % Mod;
    }
};