class FTrie
{
    int Score;
    array<FTrie*, 26> Children;
public:
    FTrie ()
    {
        Score = 0;
        Children.fill(nullptr);
    }
    
    void Add(const string &S, const int Index)
    {
        if (Index)
        {
            Score++;
        }
        
        if (Index == S.size())
        {
            return;
        }
        
        int SIndex = S[Index] - 'a';
        if (!Children[SIndex])
        {
            Children[SIndex] = new FTrie();
        }
        
        Children[SIndex]->Add(S, Index + 1);
    }
    
    int GetScore(const string &S, int Index)
    {
        if (Index == S.size())
        {
            return Score;
        }
        return Score + Children[S[Index] - 'a']->GetScore(S, Index + 1);
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words)
    {
        FTrie *Trie = new FTrie();
        for (const string &S : words)
        {
            Trie->Add(S, 0);
        }
        
        vector<int> Scores;
        for (const string &S : words)
        {
            Scores.push_back(Trie->GetScore(S, 0));
        }
        
        return Scores;
    }
};