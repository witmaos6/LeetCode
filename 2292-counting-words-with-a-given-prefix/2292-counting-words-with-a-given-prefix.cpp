class Solution {
public:
    int prefixCount(vector<string>& words, string pref)
    {
        int Count = 0;
        for(string& Word : words)
        {
            if(IsPrefix(Word, pref))
            {
                Count++;
            }
        }
        return Count;
    }
private:
    bool IsPrefix(const string& Word, const string& Prefix)
    {
        const int WordSize = static_cast<int>(Word.size());
        const int PrefixSize = static_cast<int>(Prefix.size());

        if(WordSize < PrefixSize)
            return false;

        for(int i = 0; i < PrefixSize; i++)
        {
            if(Word[i] != Prefix[i])
                return false;
        }
        return true;
    }
};