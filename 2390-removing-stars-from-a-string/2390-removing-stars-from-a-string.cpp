class Solution {
    const char Erase = '*';
public:
    string removeStars(string s)
    {
        int N = static_cast<int>(s.size());
        string Result;
        int Count = 0;
        
        for(int i = N - 1; i >= 0; i--)
        {
            if(s[i] == Erase)
            {
                Count++;
            }
            else
            {
                if(Count > 0)
                {
                    Count--;
                }
                else
                {
                    Result += s[i];
                }
            }
        }
        
        reverse(Result.begin(), Result.end());
        
        return Result;
    }
};