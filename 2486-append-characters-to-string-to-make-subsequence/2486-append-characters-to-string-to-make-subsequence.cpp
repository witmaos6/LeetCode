class Solution {
public:
    int appendCharacters(string s, string t)
    {
        const int SSize = static_cast<int>(s.size());
        const int TSize = static_cast<int>(t.size());
        
        int TIndex = 0;
        for(int SIndex = 0; SIndex < SSize; SIndex++)
        {
            if(s[SIndex] == t[TIndex])
            {
                TIndex++;
            }
        }
        
        return TSize - TIndex;
    }
};