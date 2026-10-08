class Solution {
public:
    string removeOuterParentheses(string s)
    {
        const int N = s.size();
        int Depth = 0;
        string Result;
        stack<int> Indices;

        for(int i = 0; i < N; i++)
        {
            if(s[i] == '(')
            {
                Depth++;
                Indices.push(i);
            }
            else if(s[i] == ')')
            {
                Depth--;
                if(Depth == 0)
                {
                    int Index = Indices.top();
                    Result += s.substr(Index + 1, i - Index - 1);
                }
                Indices.pop();
            }
        }
        return Result;
    }
};