class Solution {
    using P = pair<int, int>;
public:
    int longestValidParentheses(string s)
    {
        const int N = s.size();
        stack<int> Begins;
        vector<P> Memo;

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

                Memo.push_back({Begin, i});
            }
        }

        int Result = 0;
        int Count = 0;
        int PrevEnd = -1;
        for(auto&[Begin, End] : Memo)
        {
            if(PrevEnd + 1 >= Begin)
            {
                Count += End - Begin + 1;
            }
            else
            {
                Count = End - Begin + 1;
            }
            Result = max(Result, Count);
            PrevEnd = End;
        }
        return Result;
    }
};