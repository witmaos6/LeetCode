class Solution {
    const char Erase = '*';
public:
    string removeStars(string s)
    {
        int N = static_cast<int>(s.size());
        string Result;
        
        for(int i = 0; i < N; i++)
        {
            if(s[i] == Erase)
            {
                Result.pop_back();
            }
            else
            {
                Result += s[i];
            }
        }
        
        return Result;
    }
};