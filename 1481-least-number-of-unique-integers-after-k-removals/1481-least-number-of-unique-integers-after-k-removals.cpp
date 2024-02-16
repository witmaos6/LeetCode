class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k)
    {
        unordered_map<int, int> FreqTable;
        for(int Num : arr)
        {
            FreqTable[Num]++;
        }
       
        priority_queue<int, vector<int>, greater<>> MinHeap;
        for(auto& [Num, Freq] : FreqTable)
        {
            MinHeap.push(Freq);
        }
        
        int Count = static_cast<int>(MinHeap.size());
        while(!MinHeap.empty())
        {
            int Freq = MinHeap.top();
            MinHeap.pop();
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