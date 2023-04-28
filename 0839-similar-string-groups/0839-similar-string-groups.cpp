class Solution {
    vector<int> Parent;
    vector<int> Rank;
    int Sum = 0;
public:
    int numSimilarGroups(vector<string>& strs)
    {
        int N = static_cast<int>(strs.size());
        int StrLength = static_cast<int>(strs[0].size());
        Parent.resize(300);
        Rank.resize(300, 1);
        Sum = N;
        
        for(int i = 0; i < N; i++)
        {
            Parent[i] = i;
        }
        
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                if(AreSimilar(strs[i], strs[j], StrLength))
                {
                    Union(i, j);
                }
            }
        }
        
        return Sum;
    }
    
private:
    bool AreSimilar(const string& Str1, const string& Str2, const int StrLength)
    {
        int Different = 0;
        
        for(int i = 0; i < StrLength; i++)
        {
            if(Str1[i] != Str2[i])
            {
                Different++;
                if(Different > 2)
                {
                    return false;
                }
            }
        }
        
        return Different <= 2;
    }
    
    void Union(int i, int j)
    {
        int P1 = Find(i);
        int P2 = Find(j);
        
        if(P1 == P2)
        {
            return;
        }
        if(Rank[P1] < Rank[P2])
        {
            swap(P1, P2);
        }
        
        Parent[P2] = P1;
        Rank[P1] += Rank[P2];
        Sum--;
    }
    
    int Find(int i)
    {
        while(i != Parent[i])
        {
            Parent[i] = Parent[Parent[i]];
            i = Parent[i];
        }
        
        return i;
    }
};