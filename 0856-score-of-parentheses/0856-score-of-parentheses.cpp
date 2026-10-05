class Solution {
public:
    int scoreOfParentheses(string s)
    {
        const int N = s.size();
        int Score = 0;
        int Depth = 0;

        for(int i = 0; i < N; i++)
        {
            if(s[i] == '(')
            {
                Depth++;
            }
            else
            {
                Depth--;
                if(s[i - 1] == '(')
                {
                    Score += (1 << Depth);
                }
            }
        }

        return Score;
    }
};