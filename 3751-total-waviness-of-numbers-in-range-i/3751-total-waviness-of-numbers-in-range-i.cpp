class Solution {
public:
    int totalWaviness(int num1, int num2)
    {
        int Result = 0;
        for(int i = max(100, num1); i <= num2; i++)
        {
            string Str = to_string(i);
            int N = Str.size();
            for(int i = 1; i < N - 1; i++)
            {
                if((Str[i] > Str[i - 1] && Str[i] > Str[i + 1]) || (Str[i] < Str[i - 1] && Str[i] < Str[i + 1]))
                {
                    Result++;
                }
            }
        }
        return Result;
    }
};