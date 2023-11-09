class Solution {
    const int Mod = 1e9 + 7;
public:
    int countHomogenous(string s)
    {
        s.push_back('0');
        char PrevC = '0';
        long long Memo = 1;
        long long Result = 0;
        
        for(char C : s)
        {
            if(C == PrevC)
            {
                Memo++;
            }
            else
            {
                long long Temp = (1 + Memo) * Memo / 2;
                Result = (Result + Temp) % Mod;
                Memo = 1;
                PrevC = C;
            }
        }
        
        return static_cast<int>(Result - 1);
    }
};