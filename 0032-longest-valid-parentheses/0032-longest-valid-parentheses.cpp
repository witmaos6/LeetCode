class Solution {
public:
    int longestValidParentheses(string s)
    {
        const int N = s.size();
        stack<int> Begins;
        vector<bool> Memo(N + 1);

        for(int i = 0; i < N; i++)
        {
            if(s[i] == '(')
            {
                Begins.push(i);
            }
            else if(s[i] == ')' && !Begins.empty())
            {
                int Begin = Begins.top();
                Begins.pop();

                for(int j = Begin; j <= i; j++)
                {
                    if(Memo[j] == true)
                    {
                        Memo[i] = true;
                        break;
                    }
                    Memo[j] = true;
                }
            }
        }

        int Result = 0;
        int Count = 0;
        for(bool B : Memo)
        {
            if(B)
            {
                Count++;
            }
            else
            {
                Result = max(Result, Count);
                Count = 0;
            }
        }

        return Result;
    }
};