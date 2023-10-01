class Solution {
public:
    string reverseWords(string s)
    {
        int N = static_cast<int>(s.size());
        int Begin = 0;
        
        for(int i = 0; i <= N; i++)
        {
            if(s[i] == ' ' || i == N)
            {
                reverse(s.begin() + Begin, s.begin() + i);
                Begin = i + 1;
            }
        }
        
        return s;
    }
};