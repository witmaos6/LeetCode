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
            else
            {
                if(St.empty())
                    return false;

                if(C == ')' && St.top() == '(')
                {
                    St.pop();
                }
                else if(C == '}' && St.top() == '{')
                {
                    St.pop();
                }
                else if(C == ']' && St.top() == '[')
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