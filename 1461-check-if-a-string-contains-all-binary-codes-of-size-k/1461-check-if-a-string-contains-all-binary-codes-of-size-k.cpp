class Solution {
public:
    bool hasAllCodes(string s, int k)
    {
        const int N = static_cast<int>(s.size());
        if(N < k)
            return false;

        unordered_set<string> Table;
        for(int i = 0; i <= N - k; i++)
        {
            string Code = s.substr(i, k);
            Table.insert(Code);
        }

        return Table.size() == (1 << k);
    }
};