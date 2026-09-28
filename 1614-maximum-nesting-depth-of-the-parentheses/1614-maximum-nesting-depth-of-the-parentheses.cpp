class Solution {
public:
    int maxDepth(string s)
    {
        int Open = 0;
        int Result = 0;
        for(char& C : s)
        {
            if(C == '(')
            {
                Open++;
                Result = max(Result, Open);
            }
            else if(C == ')')
            {
                Open--;
            }
        }
        return Result;
    }
};