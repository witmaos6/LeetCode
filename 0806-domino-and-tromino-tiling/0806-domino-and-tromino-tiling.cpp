class Solution {
    const int Mod = 1e9 + 7;
public:
    int numTilings(int n)
    {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        if(n == 3)
            return 5;
        
        vector<int> Memo(n + 1);
        Memo[0] = 1;
        Memo[1] = 1;
        Memo[2] = 2;
        Memo[3] = 5;

        for(int i = 4; i <= n; i++)
        {
            Memo[i] = (Memo[i - 1] * 2 + long(Memo[i - 3])) % Mod;
        }
        return Memo[n];
    }
};