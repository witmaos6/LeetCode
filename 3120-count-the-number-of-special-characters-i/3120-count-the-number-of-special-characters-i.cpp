class Solution {
public:
    int numberOfSpecialChars(string word)
    {
        vector<pair<int, int>> Table(26);

        for(char& C : word)
        {
            if(C >= 'A' && C <= 'Z')
            {
                Table[C - 'A'].first++;
            }
            else if(C >= 'a' && C <= 'z')
            {
                Table[C - 'a'].second++;
            }
        }

        int Result = 0;
        for(auto& [Lower, Upper] : Table)
        {
            if(Lower >= 1 && Upper >= 1)
            {
                Result++;
            }
        }
        return Result;
    }
};