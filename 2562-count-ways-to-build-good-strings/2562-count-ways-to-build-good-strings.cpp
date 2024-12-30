class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        const int Mod = 1e9 + 7;
        vector<int> Memo(high + 1);
        Memo[0] = 1;

        int Result = 0;
        for(int i = 1; i <= high; i++)
        {
            if(i >= zero)
            {
                Memo[i] = (Memo[i] + Memo[i - zero]) % Mod;
            }
            if(i >= one)
            {
                Memo[i] = (Memo[i] + Memo[i - one]) % Mod;
            }
            if(i >= low)
            {
                Result = (Result + Memo[i]) % Mod;
            }
        }

        return Result;
    }
};