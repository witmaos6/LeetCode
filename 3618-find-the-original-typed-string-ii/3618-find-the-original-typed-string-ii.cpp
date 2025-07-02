class Solution {
public:
    int possibleStringCount(string word, int k)
    {
        const int Mod = 1e9 + 7;

        const int N = static_cast<int>(word.size());
        vector<int> Groups;
        int Count = 1;
        for(int i = 1; i < N; i++)
        {
            if(word[i] == word[i - 1])
            {
                Count++;
            }
            else
            {
                Groups.push_back(Count);
                Count = 1;
            }
        }
        Groups.push_back(Count);

        long long Total = 1;
        for(int& Num : Groups)
        {
            Total = (Total * Num) % Mod;
        }

        const int GroupSize = static_cast<int>(Groups.size());
        if(k <= GroupSize)
            return Total;

        vector<int> DP(k);
        DP[0] = 1;

        for(int& Num : Groups)
        {
            vector<int> Curr(k);
            long long Sum = 0;
            for(int i = 0; i < k; i++)
            {
                if(i > 0)
                {
                    Sum = (Sum + DP[i - 1]) % Mod;
                }
                if(i > Num)
                {
                    Sum = (Sum - DP[i - Num - 1] + Mod) % Mod;
                }
                Curr[i] = Sum;
            }
            DP = Curr;
        }

        long long Invalid = 0;
        for(int i = GroupSize; i < k; i++)
        {
            Invalid = (Invalid + DP[i]) % Mod;
        }
        return (Total - Invalid + Mod) % Mod;
    }
};