class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int, int> NumToFreq;
        
        for(int Num : arr)
        {
            NumToFreq[Num]++;
        }
        
        array<bool, 1001> FreqTable = {false};
        
        for(auto& [Num, Freq] : NumToFreq)
        {
            if(FreqTable[Freq])
            {
                return false;
            }
            FreqTable[Freq] = true;
        }
        
        return true;
    }
};