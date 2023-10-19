class Solution {
    const char Backspace = '#';
public:
    bool backspaceCompare(string s, string t)
    {
        int CountS = ExcuteBackspace(s);
        int CountT = ExcuteBackspace(t);

        if(CountS != CountT)
        {
            return false;
        }

        for(int i = 0; i < CountS; i++)
        {
            if(s[i] != t[i])
            {
                return false;
            }
        }
        return true;
    }
private:
    int ExcuteBackspace(string& s)
    {
        int CountErase = 0;

        for(size_t i = 0; i < s.size(); i++)
        {
            if(s[i] == Backspace)
            {
                CountErase--;
                CountErase = max(0, CountErase);
            }
            else
            {
                s[CountErase] = s[i];
                CountErase++;
            }
        }

        return CountErase;
    }
};