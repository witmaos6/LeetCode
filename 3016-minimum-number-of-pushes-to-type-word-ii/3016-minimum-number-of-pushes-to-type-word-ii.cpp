class Solution {
public:
    int minimumPushes(string word)
    {
        unordered_map<char, int> Table;
        for (char C : word)
        {
            Table[C]++;
        }
        
        priority_queue<int, vector<int>> MaxHeap;
        for (auto&[C, Freq] : Table)
        {
            MaxHeap.push(Freq);
        }
        
        int TotalPresses = 0;
        int KeyPosition = 0;
        
        while (!MaxHeap.empty())
        {
            TotalPresses += (KeyPosition / 8 + 1) * MaxHeap.top();
            MaxHeap.pop();
            KeyPosition++;
        }
        
        return TotalPresses;
    }
};