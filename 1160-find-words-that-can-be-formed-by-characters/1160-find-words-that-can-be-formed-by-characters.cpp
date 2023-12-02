class Solution {
    const int Begin = 'a';
public:
    int countCharacters(vector<string>& words, string chars)
    {
        vector<int> Table(128);
        for(const char C : chars)
        {
            Table[C]++;
        }
        
        const int CharsSize = static_cast<int>(chars.size());
        int Count = 0;
        
        for(const string& Word : words)
        {
            int WordSize = static_cast<int>(Word.size());
            if(WordSize > CharsSize)
            {
                continue;
            }
            
            vector<int> WordTable(128);
            for(const char C : Word)
            {
                WordTable[C]++;
            }
            
            if(IsGood(WordTable, Table))
            {
                Count += WordSize;
            }
        }
        
        return Count;
    }
    
private:
    bool IsGood(vector<int>& Table1, vector<int>& Table2)
    {
        for(int i = Begin; i < Begin + 26; i++)
        {
            if(Table2[i] < Table1[i])
            {
                return false;
            }
        }
        return true;
    }
};