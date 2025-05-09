class Solution {
public:
    int countBalancedPermutations(string num)
    {
        const int Mod = 1e9 + 7;
        const int N = static_cast<int>(num.size());
        int Sum = 0;
        for(char& C : num)
        {
            Sum += (C - '0');
        }
        if(Sum % 2)
            return 0;

        vector<long long> Fact(N + 1, 1);
        vector<long long> Inv(N + 1, 1);
        vector<long long> InvFact(N + 1, 1);

        for(int i = 1; i <= N; i++)
        {
            Fact[i] = Fact[i - 1] * i % Mod;
        }
        for(int i = 2; i <= N; i++)
        {
            Inv[i] = Mod - (Mod / i) * Inv[Mod % i] % Mod;
        }
        for(int i = 1; i <= N; i++)
        {
            InvFact[i] = InvFact[i - 1] * Inv[i] % Mod;
        }

        int HalfSum = Sum / 2;
        int HalfLen = N / 2;
        vector<vector<int>> Memo(HalfSum + 1, vector<int>(HalfLen + 1));
        Memo[0][0] = 1;

        vector<int> Digits(10);
        for(char& C : num)
        {
            int D = (C - '0');
            Digits[D]++;

            for(int i = HalfSum; i >= D; i--)
            {
                for(int j = HalfLen; j > 0; j--)
                {
                    Memo[i][j] = (Memo[i][j] + Memo[i - D][j - 1]) % Mod;
                }
            }
        }

        long long Result = Memo[HalfSum][HalfLen];
        Result = Result * Fact[HalfLen] % Mod * Fact[N - HalfLen] % Mod;
        for(int& D : Digits)
        {
            Result = Result * InvFact[D] % Mod;
        }
        return Result;
    }
};