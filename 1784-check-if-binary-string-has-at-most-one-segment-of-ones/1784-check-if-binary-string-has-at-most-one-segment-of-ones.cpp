class Solution {
public:
    bool checkOnesSegment(string s)
    {
        char Prev = '1';
        for(char& C : s)
        {
            if(C == '1')
            {
                if(Prev == '0')
                    return false;
            }
            Prev = C;
        }
        return true;
    }
};