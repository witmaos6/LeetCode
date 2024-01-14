class Solution {
public:
    bool closeStrings(string word1, string word2)
    {
        const size_t N = word1.size();
        if(word2.size() != N)
        {
            return false;
        }
        
        vector<int> Word1Table = GetWordTable(word1);
        vector<int> Word2Table = GetWordTable(word2);
        
        vector<int> OperArr1, OperArr2;
        
        for(size_t i = 0; i < 26; i++)
        {
            if(Word1Table[i] != Word2Table[i])
            {
                if(Word1Table[i] == 0 || Word2Table[i] == 0)
                {
                    return false;
                }
                OperArr1.push_back(Word1Table[i]);
                OperArr2.push_back(Word2Table[i]);
            }
        }
        
        sort(OperArr1.begin(), OperArr1.end());
        sort(OperArr2.begin(), OperArr2.end());
        
        const size_t M = OperArr1.size();
        for(size_t i = 0; i < M; i++)
        {
            if(OperArr1[i] != OperArr2[i])
            {
                return false;
            }
        }
        return true;
    }
    
private:
    vector<int> GetWordTable(const string& Word)
    {
        vector<int> Result(26);
        
        for(const char C : Word)
        {
            Result[C - 'a']++;
        }
        return Result;
    }
};