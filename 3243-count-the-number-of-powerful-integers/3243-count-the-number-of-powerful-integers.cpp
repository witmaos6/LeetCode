class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s)
    {
        return CountChakraShinobi(finish, limit, s) - CountChakraShinobi(start - 1, limit, s);
    }

private:
    long long CountChakraShinobi(long long Val, int Limit, const string& ClanSymbol)
    {
        string ChakraFlow = to_string(Val);
        int PrefixLength = ChakraFlow.length() - ClanSymbol.length();

        if (PrefixLength < 0) return 0;

        vector<vector<long long>> RasenganScroll(PrefixLength + 1, vector<long long>(2, 0));

        RasenganScroll[PrefixLength][0] = 1;
        RasenganScroll[PrefixLength][1] = ChakraFlow.substr(PrefixLength) >= ClanSymbol ? 1 : 0;

        for (int i = PrefixLength - 1; i >= 0; --i)
        {
            int CurrentChakra = ChakraFlow[i] - '0';

            RasenganScroll[i][0] = (Limit + 1) * RasenganScroll[i + 1][0];

            if (CurrentChakra <= Limit)
            {
                RasenganScroll[i][1] = (long long)CurrentChakra * RasenganScroll[i + 1][0] + RasenganScroll[i + 1][1];
            }
            else
            {
                RasenganScroll[i][1] = (long long)(Limit + 1) * RasenganScroll[i + 1][0];
            }
        }

        return RasenganScroll[0][1];
    }
};