class Solution {
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
                vector<bool> Booleans;
                while(!Expression.empty())
                {
                    if(Expression.top() == 't')
                    {
                        Booleans.push_back(true);
                    }
                    else if(Expression.top() == 'f')
                    {
                        Booleans.push_back(false);
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
                        if(Booleans.front() == true)
                        {
                            Expression.push('f');
                        }
                        else if(Booleans.front() == false)
                        {
                            Expression.push('t');
                        }
                    }
                    else if(Operator == '&')
                    {
                        char Result = AndOperator(Booleans);
                        Expression.push(Result);
                    }
                    else if(Operator == '|')
                    {
                        char Result = OrOperator(Booleans);
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
private:
    char AndOperator(const vector<bool>& Booleans)
    {
        for(bool B : Booleans)
        {
            if(B == false)
            {
                return 'f';
            }
        }
        return 't';
    }
    
    char OrOperator(const vector<bool>& Booleans)
    {
        for(bool B : Booleans)
        {
            if(B == true)
            {
                return 't';
            }
        }
        return 'f';
    }
};