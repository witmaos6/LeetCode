class Solution {
    using Pair = pair<int, int>;
public:
    bool parseBoolExpr(string expression)
    {
        stack<char> Expression;
        
        for(char C : expression)
        {
            if(C == '(' || C == '!' || C == '&' || C == '|' || C == 't' || C == 'f')
            {
                Expression.push(C);
            }
            else if(C == ')')
            {
                Pair Booleans = {0, 0}; // first == true, second == false
                while(!Expression.empty())
                {
                    if(Expression.top() == 't')
                    {
                        Booleans.first = 1;
                    }
                    else if(Expression.top() == 'f')
                    {
                        Booleans.second = 1;
                    }
                    else if(Expression.top() == '(')
                    {
                        Expression.pop();
                        break;
                    }
                    Expression.pop();
                }
                
                if(!Expression.empty())
                {
                    char Operator = Expression.top();
                    Expression.pop();
                    
                    if(Operator == '!')
                    {
                        if(Booleans.first == 1)
                        {
                            Expression.push('f');
                        }
                        else if(Booleans.second == 1)
                        {
                            Expression.push('t');
                        }
                    }
                    else if(Operator == '&')
                    {
                        char Result = (Booleans.second == 1) ? 'f' : 't';
                        Expression.push(Result);
                    }
                    else if(Operator == '|')
                    {
                        char Result = (Booleans.first == 1) ? 't' : 'f';
                        Expression.push(Result);
                    }
                }
            }
        }
        
        if(!Expression.empty() && Expression.top() == 't')
        {
            return true;
        }
        return false;
    }
};