class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        long long Mod = 1e9 + 7;
        if(n == 1)
            return 1;

        vector<long long> Memo(n + 1);
        Memo[1] = 1;
        long long Window = 0;
        for(int i = 2; i <= n; i++)
        {
            int Enter = i - delay;
            int Exit = i - forget;

            if(Enter >= 1)
                Window = (Window + Memo[Enter]) % Mod;
            if(Exit >= 1)
                Window = (Window - Memo[Exit] + Mod) % Mod;
            Memo[i] = Window; 
        }
        long long Result = 0;
        int Begin = max(1, n - forget + 1);
        for(int i = Begin; i <= n; i++)
        {
            Result = (Result + Memo[i]) % Mod;
        }
        return (int)Result;
    }
};