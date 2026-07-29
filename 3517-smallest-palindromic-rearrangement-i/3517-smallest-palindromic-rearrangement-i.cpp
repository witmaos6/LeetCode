class Solution {
public:
    string smallestPalindrome(string s)
    {
        const int N = s.size();
        array<int, 26> Table = {0};

        for(int i = 0; i < N / 2; i++)
        {
            Table[s[i] - 'a']++;
        }

        string Result;
        for(int i = 0; i < 26; i++)
        {
            string Side(Table[i], 'a' + i);

            Result += Side;
        }

        string Reverse = Result;
        ranges::reverse(Reverse);
        if((N & 1) == 1)
        {
            Result += s[N / 2];
        }

        return Result + Reverse;
    }
};