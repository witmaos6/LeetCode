class Solution {
public:
    bool canConstruct(string s, int k)
    {
        const int N = static_cast<int>(s.size());
        if(N == k)
            return true;

        if(N < k)
            return false;

        array<int, 26> Table = {0};
        for(int i = 0; i < N; i++)
        {
            Table[s[i] - 'a']++;
        }

        int OddCount = 0;
        for(int i = 0; i < 26; i++)
        {
            if((Table[i] & 1) == 1)
            {
                OddCount++;
            }
        }

        return OddCount <= k;
    }
};