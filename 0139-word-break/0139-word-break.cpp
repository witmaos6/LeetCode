class Solution {
    unordered_set<string> WordDict;
    unordered_map<string, bool> Memo;
    int N = 0;
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        N = static_cast<int>(s.size());
        for(string& Word : wordDict)
        {
            WordDict.insert(Word);
        }
        
        return DFS(s, 0);
    }
    
private:
    bool DFS(string& S, int Index)
    {
        if(Index >= N)
        {
            return true;
        }
        
        string Temp = S.substr(Index);
        if(Memo.find(Temp) != Memo.end())
        {
            return Memo[Temp];
        }
        
        string Sub;
        for(int i = Index; i < N; i++)
        {
            Sub += S[i];
            
            if(WordDict.find(Sub) != WordDict.end())
            {
                if(DFS(S, i + 1))
                {
                    Memo[Sub] = true;
                    return Memo[Sub];
                }
            }
        }
        
        Memo[Sub] = false;
        return Memo[Sub];
    }
};