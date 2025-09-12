class Solution {
public:
    bool doesAliceWin(string s)
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            char c = s[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                return true;
            }
        }
        return false;
    }
};