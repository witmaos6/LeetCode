class Solution {
public:
    string smallestPalindrome(string s, int k)
    {
        const int N = s.size();
        vector<int> Table(26);

        for(char& C : s)
        {
            Table[C - 'a']++;
        }

        char Mid = 0;
        vector<int> Half(26);
        int Len = 0;
        for(int i = 0; i < 26; i++)
        {
            Half[i] = Table[i] / 2;
            Len += Half[i];
            if(Table[i] % 2)
            {
                Mid = char('a' + i);
            }
        }

        if(CountWays(Half) < k)
            return "";

        string Left;
        for(int Pos = 0; Pos < Len; Pos++)
        {
            for(int Ch = 0; Ch < 26; Ch++)
            {
                if(Half[Ch] == 0)
                    continue;
                
                Half[Ch]--;
                long long Ways = CountWays(Half);

                if(Ways >= k)
                {
                    Left += char('a' + Ch);
                    break;
                }

                k -= Ways;
                Half[Ch]++;
            }
        }

        string Right = Left;
        ranges::reverse(Right);
        if(Mid)
            return Left + Mid + Right;
        return Left + Right;
    }
private:
    long long CountWays(vector<int>& Table)
    {
        long long Remaining = 0;
        for(int& Freq : Table)
            Remaining += Freq;
        
        long long Result = 1;
        for(int& Freq : Table)
        {
            if(Freq == 0)
                continue;
            
            long long Part = CombCapped(Remaining, Freq);
            Result *= Part;
            if(Result > LIMIT)
                return LIMIT + 1;
            
            Remaining -= Freq;
        }
        return Result;
    }

const long long LIMIT = 1000000;
private:
    long long CombCapped(long long N, long long R)
    {
        if(R < 0 || R > N)
            return 0;

        R = min(R, N - R);
        if(R == 0)
            return 1;
        
        __int128 Result = 1;
        for(long long i = 1; i <= R; i++)
        {
            Result = Result * (N - R + i) / i;
            if(Result > LIMIT)
                return LIMIT + 1;
        }
        return (long long)Result;
    }
};