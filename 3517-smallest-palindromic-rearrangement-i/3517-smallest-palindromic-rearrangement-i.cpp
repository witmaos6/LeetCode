class Solution {
public:
    string smallestPalindrome(string s)
    {
        const int N = s.size();
        array<int, 26> Table = {0};

        for(char& C : s)
        {
            Table[C - 'a']++;
        }

        string Result;
        int Odd = -1;
        for(int i = 0; i < 26; i++)
        {
            string Side(Table[i] / 2, 'a' + i);
            if((Table[i] & 1) == 1)
            {
                Odd = i;
            }

            Result += Side;
        }

        string Reverse = Result;
        if(Odd != -1)
        {
            Reverse += ('a' + Odd);
        }
        ranges::reverse(Reverse);
        return Result + Reverse;
    }
};