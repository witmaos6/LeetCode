class Solution {
public:
    int countPalindromicSubsequence(string s)
    {
        const int N = static_cast<int>(s.size());
        vector<pair<int, int>> Table(26, {-1, -1});
        
        for(int i = 0; i < N; i++)
        {
            if(Table[s[i] - 'a'].first == -1)
            {
                Table[s[i] - 'a'].first = i;
            }
            else
            {
                Table[s[i] - 'a'].second = i;
            }
        }
        
        int Result = 0;
        for(int i = 0; i < 26; i++)
        {
            int Begin = Table[i].first;
            if(Begin == -1)
                continue;
            
            int End = Table[i].second;
            
            unordered_set<char> MiddleChar;
            for(int j = Begin + 1; j < End; j++)
            {
                MiddleChar.insert(s[j]);
            }
            Result += static_cast<int>(MiddleChar.size());
        }
        
        return Result;
    }
};