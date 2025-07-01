class Solution {
public:
    int possibleStringCount(string word)
    {
        int Count = 1;
        char PrevC = '-';
        for(char C : word)
        {
            if(C == PrevC)
            {
                Count += 1;
            }
            PrevC = C;
        }
        return Count;
    }
};