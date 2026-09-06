class Solution {
public:
    int numDistinct(string s, string t)
    {
        if(s.size() < t.size())
            return 0;

        int SSize = s.size();
        int TSize = t.size();

        vector<unsigned long long> Memo(TSize + 1);
        Memo[TSize] = 1;

        for(int i = SSize - 1; i >= 0; i--)
        {
            char SC = s[i];

            for(int j = 0; j < TSize; j++)
            {
                char TC = t[j];
                if(SC == TC)
                {
                    Memo[j] += Memo[j + 1];
                }
            }
        }
        return Memo[0];
    }
};