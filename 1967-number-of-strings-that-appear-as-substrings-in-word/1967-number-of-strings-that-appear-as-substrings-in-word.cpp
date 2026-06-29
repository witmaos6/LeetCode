class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word)
    {
        int Count = 0;
        for(const string& Pattern : patterns)
        {
            size_t Index = word.find(Pattern);
            if(Index != string::npos)
            {
                Count++;
            }
        }
        return Count;
    }
};