class Solution {
    unordered_map<string, vector<char>> Table;
    unordered_map<string, bool> Check;
public:
    bool pyramidTransition(string bottom, vector<string>& allowed)
    {
        for(string& S : allowed)
        {
            Table[S.substr(0, 2)].push_back(S[2]);
        }

        return DFS(0, "", bottom);
    }

    bool DFS(int i, string Curr, const string& Bottom)
    {
        if(Bottom.size() == 1)
            return true;

        if(i == Bottom.size() - 1)
        {
            if(Check.count(Curr))
            {
                return Check[Curr];
            }
            return Check[Curr] = DFS(0, "", Curr);
        }

        string S = Bottom.substr(i, 2);
        if(Table.count(S) == 0)
            return false;

        for(char& C : Table[S])
        {
            if(DFS(i + 1, Curr + C, Bottom))
                return true;
        }
        return false;
    }
};