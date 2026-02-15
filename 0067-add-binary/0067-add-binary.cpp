class Solution {
public:
    string addBinary(string a, string b)
    {
        int i = static_cast<int>(a.size()) - 1;
        int j = static_cast<int>(b.size()) - 1;

        string Result;
        int Temp = 0;

        while(i >= 0 || j >= 0 || Temp != 0)
        {
            if(i >= 0)
            {
                Temp += a[i] - '0';
                i--;
            }
            if(j >= 0)
            {
                Temp += b[j] - '0';
                j--;
            }

            Result += (Temp % 2 + '0');
            Temp >>= 1;
        }

        reverse(Result.begin(), Result.end());

        return Result;
    }
};