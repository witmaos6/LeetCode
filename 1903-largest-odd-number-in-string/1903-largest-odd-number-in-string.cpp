class Solution {
public:
    string largestOddNumber(string num)
    {
        const int N = static_cast<int>(num.size());
        
        string Result;
        for(int i = N - 1; i >= 0; i--)
        {
            if(num[i] & 1)
            {
                Result = num.substr(0, i + 1);
                break;
            }
        }
        
        return Result;
    }
};