class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k)
    {
        unordered_map<int, int> FreqTable;
        for(int Num : arr)
        {
            FreqTable[Num]++;
        }
       
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Heap;
        for(auto& [Num, Freq] : FreqTable)
        {
            Heap.push({Freq, Num});
        }
        
        int Count = static_cast<int>(Heap.size());
        while(!Heap.empty())
        {
            auto[Freq, Num] = Heap.top();
            Heap.pop();
            
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