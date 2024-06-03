class Solution {
public:
    int appendCharacters(string s, string t)
    {
        const int TSize = static_cast<int>(t.size());
        
        int TIndex = 0;
        for(char C : s)
        {
            if(TIndex < TSize && C == t[TIndex])
            {
                TIndex++;
            }
        }
        
        return TSize - TIndex;
    }
};