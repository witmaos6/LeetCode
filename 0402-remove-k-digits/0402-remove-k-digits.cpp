class Solution {
public:
    string removeKdigits(string num, int k)
    {
        string Result;
        for(char Digit : num)
        {
            while(!Result.empty() && Result.back() > Digit && k > 0)
            {
                Result.pop_back();
                k--;
            }
            if(!Result.empty() || Digit != '0')
            {
                Result += Digit;
            }
        }
        while(!Result.empty() && k > 0)
        {
            Result.pop_back();
            k--;
        }
        
        return Result.empty() ? "0" : Result;
    }
};