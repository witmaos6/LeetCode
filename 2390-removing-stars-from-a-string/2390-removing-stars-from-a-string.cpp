class Solution {
    const char Erase = '*';
public:
    string removeStars(string s)
    {
        int N = static_cast<int>(s.size());
        int ToLeft = 0;
        
        for(int i = 0; i < N; i++)
        {
            if(s[i] == Erase)
            {
                ToLeft--;
            }
            else
            {
                s[ToLeft] = s[i];
                ToLeft++;
            }
        }
        
        return s.substr(0, ToLeft);
    }
};