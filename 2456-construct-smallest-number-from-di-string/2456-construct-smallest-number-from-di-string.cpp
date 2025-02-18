class Solution {
public:
    string smallestNumber(string pattern)
    {
        const int N = static_cast<int>(pattern.size());
        string Result = "1";
        string Temp;
        for(int i = 0; i < N; i++)
        {
            if(pattern[i] == 'I')
            {
                Result += Temp + char(i + '2');
                Temp = "";
            }
            else
            {
                Temp = char(Result.back()) + Temp;
                Result.pop_back();
                Result += char(i + '2');
            }
        }

        return Result + Temp;
    }
};