class Solution {
    int N = 0;
public:
    bool repeatedSubstringPattern(string s)
    {
        N = static_cast<int>(s.size());
        
        string Sub;
        int SubSize = 0;
        
        for(int i = 0; i < N / 2; i++)
        {
            Sub += s[i];
            SubSize++;
            
            if((N % SubSize) == 0 && IsRepeat(s, Sub, SubSize))
            {
                return true;
            }
        }
        
        return false;
    }
    
private:
    bool IsRepeat(const string& s, const string& Sub, int SubSize)
    {
        for(int i = 0; i < N; i += SubSize)
        {
            if(s.substr(i, SubSize) != Sub)
            {
                return false;
            }
        }
        return true;
    }
};