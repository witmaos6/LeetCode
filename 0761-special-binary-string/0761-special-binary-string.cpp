class Solution {
public:
    string makeLargestSpecial(string s)
    {
        int Count = 0;
        int i = 0;
        vector<string> Split;

        for(int j = 0; j < s.size(); j++)
        {
            Count += (s[j] == '1') ? 1 : -1;

            if(Count == 0)
            {
                Split.push_back('1' + makeLargestSpecial(s.substr(i + 1, j - i -1)) + '0');
                i = j + 1;
            }
        }

        sort(Split.begin(), Split.end(), greater<string>());

        string Result;
        for(const string& Str : Split)
        {
            Result += Str;
        }
        return Result;
    }
};