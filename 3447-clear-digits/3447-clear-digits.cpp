class Solution {
public:
    string clearDigits(string s)
    {
        const char Erase = '-';
        const int N = static_cast<int>(s.size());
        
        for(int i = 0; i < N; i++)
        {
            if(isdigit(s[i]))
            {
                s[i] = Erase;
                
                for(int j = i - 1; j >= 0; j--)
                {
                    if(!isdigit(s[j]) && s[j] != Erase)
                    {
                        s[j] = Erase;
                        break;
                    }
                }
            }
        }

        string Result;
        for(int i = 0; i < N; i++)
        {
            if(s[i] != Erase)
            {
                Result += s[i];
            }
        }

        return Result;
    }
};