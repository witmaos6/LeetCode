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
        for(auto& [Begin, End] : Table)
        {
            if(Begin == -1)
                continue;
            
            unordered_set<char> MiddleChar;
            for(int i = Begin + 1; i < End; i++)
            {
                MiddleChar.insert(s[i]);
            }
            Result += static_cast<int>(MiddleChar.size());
        }
        
        return Result;
    }
};