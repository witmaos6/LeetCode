class Solution {
public:
    string reverseWords(string s)
    {
        s += ' ';
        int N = static_cast<int>(s.size());
        int Begin = 0;
        
        for(int i = 0; i < N; i++)
        {
            if(s[i] == ' ')
            {
                reverse(s.begin() + Begin, s.begin() + i);
                Begin = i + 1;
            }
        }
        
        s.pop_back();
        return s;
    }
};