class Solution {
public:
    int maxDifference(string s)
    {
        vector<int> Table(26);
        for(char& C : s)
        {
            Table[C - 'a']++;
        }

        int MaxOdd = 0;
        int MinEven = INT_MAX;

        for(int& Freq : Table)
        {
            if(Freq == 0)
            {
                continue;
            }
            if((Freq & 1) == 1)
            {
                MaxOdd = max(MaxOdd, Freq);
            }
            else
            {
                MinEven = min(MinEven, Freq);
            }
        }

        return MaxOdd - MinEven;
    }
};