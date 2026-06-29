class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word)
    {
        int Count = 0;
        for(const string& Pattern : patterns)
        {
            if(word.find(Pattern) != string::npos)
            {
                Count++;
            }
        }
        return Count;
    }
};