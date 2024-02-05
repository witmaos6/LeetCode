class Solution {
public:
    int firstUniqChar(string s)
    {
        const int N = static_cast<int>(s.size());
        vector<int> Table(26);
        
        for(int i = 0; i < N; i++)
        {
            Table[s[i] - 'a']++;
        }
        
        for(int i = 0; i < N; i++)
        {
            if(Table[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};