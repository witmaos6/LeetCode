class Solution {
public:
    string removeOuterParentheses(string s)
    {
        string Result;
        int Open = 0;

        for(char& C : s)
        {
            if(C == '(')
            {
                if(Open > 0)
                    Result += '(';
                
                Open++;
            }
            else
            {
                Open--;
                if(Open > 0)
                    Result += ')';
            }
        }
        
        return Result;
    }
};