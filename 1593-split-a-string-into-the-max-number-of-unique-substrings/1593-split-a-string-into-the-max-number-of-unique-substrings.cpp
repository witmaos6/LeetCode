class Solution {
    unordered_set<string> Table;
    int N = 0;
    int MaxSplit = 0;
public:
    int maxUniqueSplit(string s)
    {
        N = static_cast<int>(s.size());
        string SubStr;
        for(int i = 0; i < N; ++i)
        {
            SubStr += s[i];
            
            if(Table.find(SubStr) == Table.end())
            {
                Table.insert(SubStr);
                
                BackTracking(s, i);
                
                Table.erase(SubStr);
            }
        }
        
        return MaxSplit;
    }
    
private:
    void BackTracking(const string& S, const int Index)
    {
        if (Table.size() + (S.size() - Index) <= MaxSplit)
            return;
        
        if(Index + 1 >= N)
        {
            MaxSplit = max(MaxSplit, static_cast<int>(Table.size()));
            return;
        }
        
        string SubStr;
        for(int i = Index + 1; i < N; ++i)
        {
            SubStr += S[i];
            
            if(Table.find(SubStr) == Table.end())
            {
                Table.insert(SubStr);
                
                BackTracking(S, i);
                
                Table.erase(SubStr);
            }
        }
    }
};