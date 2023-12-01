class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        string Word1, Word2;
        
        for(const string& Word : word1)
        {
            Word1 += Word;
        }
        for(const string& Word : word2)
        {
            Word2 += Word;
        }
        
        return Word1 == Word2;
    }
};