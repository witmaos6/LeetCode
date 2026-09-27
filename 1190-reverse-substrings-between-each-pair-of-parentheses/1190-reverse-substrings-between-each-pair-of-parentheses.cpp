class Solution {
public:
    string reverseParentheses(string s)
    {
        stack<int> St;
        const int N = s.size();

        for(int i = 0; i < N; i++)
        {
            if(s[i] == '(')
            {
                St.push(i);
            }
            else if(s[i] == ')')
            {
                int Begin = St.top();
                St.pop();
                reverse(s.begin() + Begin + 1, s.begin() + i);
            }
        }

        string Result;
        for(char& C : s)
        {
            if(C != '(' && C != ')')
                Result += C;
        }
        return Result;
    }
};