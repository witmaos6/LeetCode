class Solution {
public:
    char processStr(string s, long long k)
    {
        long long Result = 0;
        for(const char& C : s)
        {
            if(C == '*')
            {
                Result = (Result == 0) ? Result : Result - 1;
            }
            else if(C == '#')
            {
                Result *= 2;
            }
            else if(C == '%')
            {
            }
            else
            {
                Result++;
            }
        }
        if(k >= Result)
            return '.';

        const int N = s.size();
        for(int i = N - 1; i >= 0; i--)
        {
            char C = s[i];

            if(C == '*')
            {
                Result++;
            }
            else if(C == '#')
            {
                long long Mid = Result / 2;
                k = (k < Mid) ? k : k - Mid;
                Result /= 2;
            }
            else if(C == '%')
            {
                long long Mid = Result / 2;
                k = 2 * Mid - k;
                if(Result % 2 == 0)
                    k--;
            }
            else
            {
                Result--;
                if(Result == k)
                    return C;
            }
        }
        return '.';
    }
};