class Solution {
    vector<char> OpenBrackets = {'(', '{', '['};
    vector<char> CloseBrackets = {')', '}', ']'};
public:
    bool isValid(string s)
    {
        stack<char> Parentheses;
        
        for(char c : s)
        {
            if(bOpenBrackets(c))
            {
                Parentheses.push(c);
            }
            else
            {
                if(Parentheses.empty())
                {
                    return false;
                }
                if(bPairBrackets(Parentheses.top(), c))
                {
                    Parentheses.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        
        return Parentheses.empty();
    }
    
private:
    bool bOpenBrackets(char c)
    {
        for(char Bracket : OpenBrackets)
        {
            if(c == Bracket)
            {
                return true;
            }
        }
        return false;
    }
    
    bool bPairBrackets(char Open, char Close)
    {
        for(int i = 0; i < 3; i++)
        {
            if(OpenBrackets[i] == Open)
            {
                if(CloseBrackets[i] == Close)
                {
                    return true;
                }
                break;
            }
        }
        return false;
    }
};