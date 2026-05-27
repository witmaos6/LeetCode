class Solution {
public:
    int numberOfSpecialChars(string word)
    {
        const int N = word.size();
        vector<pair<int, int>> Table(26, {-1, -1});

        for(int i = 0; i < N; i++)
        {
            char C = word[i];

            if(C >= 'a')
            {
                Table[C - 'a'].first = i;
            }
            else
            {
                if(Table[C - 'A'].second == -1)
                {
                    Table[C - 'A'].second = i;
                }
            }
        }

        int Result = 0;
        for(auto& [Lower, Upper] : Table)
        {
            if(Lower != -1 && Lower < Upper)
            {
                Result++;
            }
        }
        return Result;
    }
};