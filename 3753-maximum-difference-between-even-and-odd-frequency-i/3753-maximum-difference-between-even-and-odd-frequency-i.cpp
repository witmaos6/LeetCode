class Solution {
public:
    int maxDifference(string s)
    {
        vector<int> Table(26);
        for(char& C : s)
        {
            Table[C - 'a']++;
        }

        int MaxOdd = 0, MinOdd = INT_MAX;
        int MaxEven = 0, MinEven = INT_MAX;

        for(int& Freq : Table)
        {
            if(Freq == 0)
            {
                continue;
            }
            if((Freq & 1) == 1)
            {
                MaxOdd = max(MaxOdd, Freq);
                MinOdd = min(MinOdd, Freq);
            }
            else
            {
                MaxEven = max(MaxEven, Freq);
                MinEven = min(MinEven, Freq);
            }
        }

        return MaxOdd - MinEven;
    }
};