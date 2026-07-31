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
        int Num = 1;
        for(int i = 0; i < 26; i++)
        {
            Sum += Table[i] * Num;
            if(i == 7 || i == 15 || i == 23)
            {
                Num++;
            }
        }
        return Sum;
    }
};