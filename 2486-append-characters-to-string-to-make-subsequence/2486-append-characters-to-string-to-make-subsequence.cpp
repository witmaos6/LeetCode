class Solution {
public:
    int appendCharacters(string s, string t)
    {
        const int TSize = static_cast<int>(t.size());
        
        int TIndex = 0;
        for(char C : s)
        {
            if(C == t[TIndex])
            {
                TIndex++;
            }
            if(TIndex >= TSize)
                break;
        }
        
        return TSize - TIndex;
    }
};