class Solution {
    const int Z = 'z';
public:
    bool isAnagram(string s, string t)
    {
        if(s.size() != t.size())
        {
            return false;
        }
        
        vector<int> STable(Z + 1);
        vector<int> TTable(Z + 1);
        
        const int N = static_cast<int>(s.size());
        for(int i = 0; i < N; i++)
        {
            STable[s[i]]++;
            TTable[t[i]]++;
        }
        
        return (STable == TTable);
    }
};