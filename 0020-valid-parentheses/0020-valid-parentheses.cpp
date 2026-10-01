class Solution {
public:
    bool isValid(string s)
    {
        stack<char> St;
        for(char& C : s)
        {
            if(C == '(' || C == '{' || C == '[')
            {
                St.push(C);
            }
            else if(C == ')')
            {
                if(!St.empty() && St.top() == '(')
                {
                    St.pop();
                }
                else
                {
                    return false;
                }
            }
            else if(C == '}')
            {
                if(!St.empty() && St.top() == '{')
                {
                    St.pop();
                }
                else
                {
                    return false;
                }
            }
            else if(C == ']')
            {
                if(!St.empty() && St.top() == '[')
                {
                    St.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return St.empty();
    }
};