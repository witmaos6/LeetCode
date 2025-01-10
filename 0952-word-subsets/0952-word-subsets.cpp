class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2)
    {
        array<int, 26> Word2Table = {0};
        for(string& Word : words2)
        {
            array<int, 26> SubsetTable = MakeWordFreq(Word);

            for(int i = 0; i < 26; i++)
            {
                Word2Table[i] = max(Word2Table[i], SubsetTable[i]);
            }
        }

        vector<string> Result;
        Result.reserve(words1.size());
        for(string& Word : words1)
        {
            array<int, 26> Freq = MakeWordFreq(Word);

            if(IsSubset(Freq, Word2Table))
            {
                Result.push_back(Word);
            }
        }
        return Result;
    }
private:
    array<int, 26> MakeWordFreq(const string& Word)
    {
        array<int, 26> Freq = {0};
        for(const char& C : Word)
        {
            Freq[C - 'a']++;
        }
        return Freq;
    }

    bool IsSubset(const array<int, 26>& Table1, const array<int, 26>& Table2)
    {
        for(int i = 0; i < 26; i++)
        {
            if(Table1[i] < Table2[i])
            {
                return false;
            }
        }
        return true;
    }
};