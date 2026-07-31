class Solution {
public:
    int minimumPushes(string word)
    {
        array<int, 26> Table;
        for(char& C : word)
        {
            Table[C - 'a']++;
        }

        ranges::sort(Table, greater<int>());

        int Sum = 0;
        for(int i = 0; i < 26; i++)
        {
            Sum += Table[i] * (i / 8 + 1);
        }
        return Sum;
    }
};