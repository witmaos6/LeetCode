class Solution {
public:
    string processStr(string s)
    {
        string Result;
        for(const char& C : s)
        {
            if(C >= 'a' && C <= 'z')
            {
                Result += C;
            }
            else if(C == '*' && !Result.empty())
            {
                Result.pop_back();
            }
            else if(C == '#')
            {
                Result = Result + Result;
            }
            else if(C == '%')
            {
                reverse(Result.begin(), Result.end());
            }
        }
        return Result;
    }
};