class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2)
    {
        vector<int> Word2Table(26);
        for(string& Word : words2)
        {
            vector<int> SubsetTable = MakeWordFreq(Word);

            for(int i = 0; i < 26; i++)
            {
                Word2Table[i] = max(Word2Table[i], SubsetTable[i]);
            }
        }

        vector<string> Result;
        Result.reserve(words1.size());

        for(string& Word : words1)
        {
            vector<int> Freq = MakeWordFreq(Word);

            if(IsSubset(Freq, Word2Table))
            {
                Result.push_back(Word);
            }
        }
        return Result;
    }
private:
    vector<int> MakeWordFreq(const string& Word)
    {
        vector<int> Freq(26);
        for(const char& C : Word)
        {
            Freq[C - 'a']++;
        }
        return Freq;
    }

    bool IsSubset(const vector<int>& Table1, const vector<int>& Table2)
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