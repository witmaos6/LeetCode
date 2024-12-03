class Solution {
public:
    string addSpaces(string s, vector<int>& spaces)
    {
        const int N = static_cast<int>(s.size());
        const int M = static_cast<int>(spaces.size());
        string Result;
        int SpaceIndex = 0;
        
        for(int i = 0; i < N; ++i)
        {
            if(i == spaces[SpaceIndex])
            {
                Result += ' ';
                if(SpaceIndex < M - 1)
                {
                    ++SpaceIndex;
                }
            }
            Result += s[i];
        }
        
        return Result;
    }
};