class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        vector<pair<int, int>> Table(26, {-1, -1});
        const int N = static_cast<int>(s.size());
        
        for(int i = 0; i < N; i++)
        {
            int Index = s[i] - 'a';
            
            if(Table[Index].first == -1)
            {
                Table[Index].first = i;
            }
            else
            {
                Table[Index].second = i;
            }
        }
        
        int MaxLength = -1;
        for(pair<int, int>& P : Table)
        {
            if(P.first != -1 && P.second != -1)
            {
                int Temp = P.second - P.first - 1;
                MaxLength = max(MaxLength, Temp);
            }
        }
        
        return MaxLength;
    }
};