class Solution {
public:
    int maxPalindromes(string s, int k)
    {
        const int N = s.size();
        int Result = 0;

        for(int i = 0; i <= N - k; i++)
        {
            if(IsPalindrome(s, i, i + k - 1))
            {
                Result++;
                i += k - 1;
            }
            else if(i + k < N && IsPalindrome(s, i, i + k))
            {
                Result++;
                i += k;
            }
        }

        return Result;
    }
private:
    bool IsPalindrome(const string& S, int Left, int Right)
    {
        while(Left < Right)
        {
            if(S[Left++] != S[Right--])
                return false;
        }
        return true;
    }
};