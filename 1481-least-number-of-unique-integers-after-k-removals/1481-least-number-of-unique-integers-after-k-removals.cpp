class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k)
    {
        unordered_map<int, int> FreqTable;
        for(int Num : arr)
        {
            FreqTable[Num]++;
        }
       
        vector<int> FreqArr;
        for(auto&[Num, Freq] : FreqTable)
        {
            FreqArr.push_back(Freq);
        }
        sort(FreqArr.begin(), FreqArr.end());
        
        int Count = static_cast<int>(FreqArr.size());
        for(int Freq : FreqArr)
        {
            if(Freq > k)
            {
                break;
            }
            k -= Freq;
            Count--;
        }
        
        return Count;
    }
};