class Solution {
public:
    bool checkStrings(string s1, string s2)
    {
        const int N = s1.size();
        array<array<int, 26>, 2> Table{};

        for(int i = 0; i < N; i++)
        {
            bool Odd = i & 1;
            Table[Odd][s1[i] - 'a']++;
            Table[Odd][s2[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++)
        {
            if(Table[0][i] >= 1 || Table[1][i] >= 1)
                return false;
        }
        return true;
    }
};