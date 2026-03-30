class Solution {
public:
    bool checkStrings(string s1, string s2)
    {
        return IsEqual(s1, s2, 0) && IsEqual(s1, s2, 1);
    }

private:
    bool IsEqual(const string& S1, const string& S2, int Index)
    {
        const int N = S1.size();
        vector<int> Table1(26);
        vector<int> Table2(26);

        for(int i = Index; i < N; i += 2)
        {
            Table1[S1[i] - 'a']++;
            Table2[S2[i] - 'a']++;
        }

        return Table1 == Table2;
    }
};