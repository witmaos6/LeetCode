class Solution {
public:
    string longestPalindrome(string s)
    {
        int N = static_cast<int>(s.size());
        string Result;
        
        for(int i = 0; i < N; i++)
        {
            string Temp = MaxPalindrome(s, i, N);
            
            if(i + 1 < N && s[i] == s[i + 1])
            {
                Temp = MaxStr(Temp, MaxPalindrome(s, i, i + 1, N));
            }
            
            Result = MaxStr(Result, Temp);
        }
        
        return Result;
    }
    
private:
    string MaxPalindrome(string& s, int i, int N)
    {
        int j = 1;
        
        while(i - j >= 0 && i + j < N)
        {
            if(s[i - j] == s[i + j])
            {
                j++;
            }
            else
            {
                break;
            }
        }
        j--;
        
        return s.substr(i - j, (j << 1) + 1);
    }
    
    string MaxPalindrome(string& s, int i, int j, int N)
    {
        while(i >=0 && j < N)
        {
            if(s[i] == s[j])
            {
                i--;
                j++;
            }
            else
            {
                break;
            }
        }
        
        return s.substr(i + 1, j - i - 1);
    }
    
    string MaxStr(const string& s1, const string& s2)
    {
        if(s1.size() > s2.size())
        {
            return s1;
        }
        return s2;
    }
};