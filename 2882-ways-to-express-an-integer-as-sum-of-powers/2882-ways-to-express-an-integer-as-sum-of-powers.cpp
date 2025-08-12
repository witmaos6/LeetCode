class Solution {
public:
    int numberOfWays(int n, int x)
    {
        const int Mod = 1e9 + 7;

        vector<int> Powers;
        int Num = 1;
        long long Power = 1;
        do
        {
            Power = 1;
            for(int i = 0; i < x; i++)
            {
                Power *= Num;
            }
            if(Power > n)
                break;

            Powers.push_back((int)Power);
            Num++;

        }while(Power <= n);

        vector<long long> Memo(n + 1);
        Memo[0] = 1;
        for(int P : Powers)
        {
            for(int i = n; i >= P; --i)
            {
                Memo[i] = (Memo[i] + Memo[i - P]) % Mod;
            }
        }
        return (int)Memo[n];
    }
};