class Solution {
    int N = 0;
public:
    int countSubstrings(string s)
    {
        N = static_cast<int>(s.size());
        
        int Count = 0;
        
        for(int i = 0; i < N; i++)
        {
            int Odd = GetCountPalindrome(s, i, i);
            int Even = GetCountPalindrome(s, i, i + 1);
            
            Count += (Odd + Even);
        }
        
        return Count;
    }
    
private:
    int GetCountPalindrome(const string& Str, int Left, int Right)
    {
        int Count = 0;
        while(Left >= 0 && Right < N)
        {
            if(Str[Left] == Str[Right])
            {
                Count++;
            }
            else
            {
                break;
            }
            Left--;
            Right++;
        }
        return Count;
    }
};