class Solution {
public:
    int takeCharacters(string s, int k)
    {
        unordered_map<char, int> Table;
        
        for(char& C : s)
        {
            Table[C]++;
        }
        
        if(Table['a'] < k || Table['b'] < k || Table['c'] < k)
            return -1;
        
        const int N = static_cast<int>(s.size());        
        int j = 0;
        int Erase = 0;
        int MinMinute = INT_MAX;
        for(int i = 0; i < N; ++i)
        {
            char C = s[i];
            --Table[C];
            ++Erase;
            
            while(Table[C] < k)
            {
                ++Table[s[j]];
                ++j;
                --Erase;
            }
            
            MinMinute = min(MinMinute, N - Erase);
        }
        
        return MinMinute;
    }
};