class Solution {
    using BracketTable = pair<int, int>;
public:
    string reverseParentheses(string s)
    {
        const int N = static_cast<int>(s.size());
        stack<BracketTable> St;
        int NrOfBrackets = 0;
        for(int i = 0; i < N; i++)
        {
            if(s[i] == '(')
            {
                ++NrOfBrackets;
                St.push({i, NrOfBrackets});
            }
            else if(s[i] == ')')
            {
                int Begin = St.top().first;
                reverse(s.begin() + Begin + 1, s.begin() + i);
                NrOfBrackets--;
                St.pop();
            }
        }
        
        string Result;
        for(char C : s)
        {
            if(C != '(' && C != ')')
                Result += C;
        }
        return Result;
    }
};