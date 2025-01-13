class Solution {
public:
    int minimumLength(string s)
    {
        array<int, 26> Table;

        for(char& C : s)
        {
            Table[C - 'a']++;
        }

        int Length = 0;
        for(int& Num : Table)
        {
            if(Num > 0)
            {
                int Count = ((Num & 1) == 1) ? 1 : 2;
                Length += Count;
            }
        }
        return Length;
    }
};