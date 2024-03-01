class Solution {
public:
    string maximumOddBinaryNumber(string s)
    {
        const int N = static_cast<int>(s.size());
        int NrOfOnes = 0;
        for(int i = 0; i < N; i++)
        {
            if(s[i] == '1')
            {
                NrOfOnes++;
            }
        }
        
        string Result;
        for(int i = 0; i < N - 1; i++)
        {
            if(NrOfOnes > 1)
            {
                Result += '1';
                NrOfOnes--;
            }
            else
            {
                Result += '0';
            }
        }
        Result += '1';
        return Result;
    }
};