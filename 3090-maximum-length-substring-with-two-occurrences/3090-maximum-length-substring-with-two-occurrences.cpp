class Solution {
public:
    int maximumLengthSubstring(string s)
    {
        const int N = s.size();

        vector<int> Table(26);
        int L = 0;
        int Result = 0;
        for(int i = 0; i < N; i++)
        {
            int Curr = s[i] - 'a';
            Table[Curr]++;

            while(Table[Curr] > 2)
            {
                Table[s[L] - 'a']--;
                L++;
            }

            Result = max(Result, i - L + 1);
        }
        return Result;
    }
};