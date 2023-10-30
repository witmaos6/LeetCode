class Solution {
    typedef pair<int, int> BitPair;
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        priority_queue<BitPair, vector<BitPair>, greater<BitPair>> MinHeap;
        for(int Num : arr)
        {
            bitset<32> Bits(Num);
            int CountBits = Bits.count();
            
            MinHeap.push({CountBits, Num});
        }
        
        vector<int> Result;
        while(!MinHeap.empty())
        {
            auto[BitCount, Num] = MinHeap.top();
            MinHeap.pop();
            
            Result.push_back(Num);
        }
        
        return Result;
    }
};