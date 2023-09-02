class Solution {
    unordered_map<int, int> Table;
public:
    int minExtraChar(string s, vector<string>& dictionary)
    {
        int Result = DFS(s, dictionary);
        
        return Result;
    }
    
private:
    int DFS(const string& S, vector<string>& Dictionary)
    {
        if(S.size() == 0)
        {
            return 0;
        }
        
        int SSize = static_cast<int>(S.size());
        
        if(Table.find(SSize) != Table.end())
        {
            return Table[SSize];
        }
        
        int MinLength = SSize;
        
        for(string& Word : Dictionary)
        {
            if(S == Word)
            {
                Table[SSize] = 0;
                return 0;
            }
            
            if(S.substr(0, Word.size()) == Word)
            {
                int Temp = DFS(S.substr(Word.size()), Dictionary);
                MinLength = min(MinLength, Temp);
            }
        }
        
        int Result = 1 + DFS(S.substr(1), Dictionary);
        MinLength = min(MinLength, Result);
        
        Table[SSize] = MinLength;
        return MinLength;
    }
};