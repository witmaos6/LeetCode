class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int, int> NumToFreq;
        for(int Num : arr)
        {
            NumToFreq[Num]++;
        }
        
        unordered_set<int> FreqTable;
        for(auto& [Num, Freq] : NumToFreq)
        {
            if(FreqTable.find(Freq) != FreqTable.end())
            {
                return false;
            }
            FreqTable.insert(Freq);
        }
        
        return true;
    }
};