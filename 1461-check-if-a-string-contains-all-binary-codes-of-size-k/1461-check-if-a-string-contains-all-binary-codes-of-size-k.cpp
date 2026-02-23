class Solution {
public:
    bool hasAllCodes(string s, int k)
    {
        const int N = static_cast<int>(s.size());
        if(N < k)
            return false;

        unordered_set<string> Table;
        string Code;
        for(int i = 0; i < k; i++)
        {
            Code += s[i];
        }
        Table.insert(Code);

        for(int i = k; i < N; i++)
        {
            Code.erase(Code.begin());
            Code += s[i];
            Table.insert(Code);
        }

        return Table.size() == (1 << k);
    }
};