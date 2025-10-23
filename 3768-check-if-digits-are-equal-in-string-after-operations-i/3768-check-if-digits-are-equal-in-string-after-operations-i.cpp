class Solution {
public:
    bool hasSameDigits(string s)
    {
        while(s.size() > 2)
        {
            string NewDigit;
            const int N = static_cast<int>(s.size());
            for(int i = 0; i < N - 1; i++)
            {
                int Digit = ((s[i] - '0') + (s[i + 1] - '0'));
                Digit %= 10;

                NewDigit += (Digit + '0');
            }
            s = NewDigit;
        }
        return (s[0] == s[1]);
    }
};