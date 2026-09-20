class Solution {
public:
    int reverseDegree(string s)
    {
        int Result = 0;
        int Product = 1;
        for(char& C : s)
        {
            Result += (ReverseInt(C) * Product);
            Product++;
        }

        return Result;
    }

    int ReverseInt(char C)
    {
        return 26 - (C - 'a');
    }
};