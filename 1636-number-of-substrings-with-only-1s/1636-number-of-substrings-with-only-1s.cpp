class Solution {
public:
    int numSub(string s)
    {
        s += '0';
        const int Mod = 1e9 + 7;
        int Count1 = 0;
        int Result = 0;

        for(char& C : s)
        {
            if(C == '1')
            {
                Count1++;
            }
            else if(C == '0')
            {
                long long Count = Count1;
                long long Temp = (Count * (Count + 1)) / 2 % Mod;
                Result += (Temp % Mod);
                Count1 = 0;
            }
        }
        return Result;
    }
};