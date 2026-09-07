class Solution {
    const int Mod = 1e9 + 7;
public:
    int distinctSubseqII(string s)
    {
        long long DP = 1;
        vector<long long> Last(26);

        for(char& C : s)
        {
            int Index = C - 'a';

            long long Prev = DP;
            DP = (2 * DP - Last[Index] + Mod) % Mod;

            Last[Index] = Prev;
        }

        return (DP - 1 + Mod) % Mod;
    }
};