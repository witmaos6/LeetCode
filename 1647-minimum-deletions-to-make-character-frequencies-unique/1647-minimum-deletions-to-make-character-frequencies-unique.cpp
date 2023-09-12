class Solution {
public:
    int minDeletions(string s)
    {
        unordered_map<char, int> Table;
        for(char C : s)
        {
            Table[C]++;
        }
        
        unordered_set<int> FreqTable;
        int Result = 0;
        
        for(pair<const char, int>& Map : Table)
        {
            int Freq = Map.second;
            
            while(Freq > 0 && FreqTable.find(Freq) != FreqTable.end())
            {
                Freq--;
                Result++;
            }
           
            FreqTable.insert(Freq);
        }
        
        return Result;
    }
};