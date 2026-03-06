class Solution {
public:
    bool checkOnesSegment(string s)
    {
        bool ExistOne = false;
        char Prev = '0';
        for(char& C : s)
        {
            if(C == '1')
            {
                if(Prev == '0')
                {
                    if(ExistOne)
                    {
                        return false;
                    }
                    else
                    {
                        ExistOne = true;
                    }
                }
            }
            Prev = C;
        }
        return true;
    }
};