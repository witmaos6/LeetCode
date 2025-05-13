class Solution {
public:
    int lengthAfterTransformations(string s, int t)
    {
        const int Mod = 1e9 + 7;
        vector<int> Table(26);
        for(char& C : s)
        {
            Table[C - 'a']++;
        }

        for(int i = 0; i < t; i++)
        {
            vector<int> Curr(26);
            for(int j = 0; j < 26; j++)
            {
                if(j == 25 && Table[j] > 0)
                {
                    Curr[0] = (Curr[0] + Table[j]) % Mod;
                    Curr[1] = (Curr[1] + Table[j]) % Mod;
                }
                else
                {
                    if(j < 25)
                    {
                        Curr[j + 1] = (Curr[j + 1], Table[j]);
                    }
                }
            }
            for(int j = 0; j < 26; j++)
            {
                Table[j] = Curr[j];
            }
        }
        int Count = 0;
        for(int& Num : Table)
        {
            Count = (Count + Num) % Mod;
        }
        return Count;
    }
};