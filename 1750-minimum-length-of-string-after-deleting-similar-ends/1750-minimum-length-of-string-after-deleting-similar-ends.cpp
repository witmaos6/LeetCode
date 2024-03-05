class Solution {
public:
    int minimumLength(string s)
    {
        int Prefix = 0;
        int Suffix = static_cast<int>(s.size()) - 1;
        
        while(Prefix < Suffix)
        {
            if(s[Prefix] != s[Suffix])
            {
                break;
            }
            
            char CurrChar = s[Prefix];
            while(Prefix <= Suffix && CurrChar == s[Prefix])
            {
                Prefix++;
            }
            while(Prefix <= Suffix && CurrChar == s[Suffix])
            {
                Suffix--;
            }
        }
        
        return Suffix - Prefix + 1;
    }
};