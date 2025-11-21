class Solution {
    using Pair = pair<int, int>;
public:
    int countPalindromicSubsequence(string s)
    {
        const int N = static_cast<int>(s.size());
        vector<Pair> Table(26, {-1, -1});

        for(int i = 0; i < N; i++)
        {
            int Index = s[i] - 'a';
            if(Table[Index].first == -1)
            {
                Table[Index].first = i;
            }
            else
            {
                Table[Index].second = i;
            }
        }

        int Result = 0;
        for(auto& [Begin, End] : Table)
        {
            if(Begin == -1)
                continue;

            vector<bool> Middle(26);
            for(int i = Begin + 1; i < End; i++)
            {
                Middle[s[i] - 'a'] = true;
            }

            int Count = 0;
            for(bool T : Middle)
            {
                if(T)
                    Count++;
            }

            Result += Count;
        }

        return Result;
    }
};