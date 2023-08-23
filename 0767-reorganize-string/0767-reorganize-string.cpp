class Solution {
public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> Table;
        for(char C : s)
        {
            Table[C]++;
        }
        
        priority_queue<pair<int, char>> MaxHeap;
        for(auto& [C, Freq] : Table)
        {
            MaxHeap.push({Freq, C});
        }
        
        string Result;
        while(MaxHeap.size() >= 2)
        {
            auto [Freq1, C1] = MaxHeap.top();
            MaxHeap.pop();
            
            auto [Freq2, C2] = MaxHeap.top();
            MaxHeap.pop();
            
            Result += C1;
            Result += C2;
            
            if(Freq1 > 1)
            {
                MaxHeap.push({Freq1 - 1, C1});
            }
            if(Freq2 > 1)
            {
                MaxHeap.push({Freq2 - 1, C2});
            }
        }
        
        while(!MaxHeap.empty())
        {
            auto [Freq, C] = MaxHeap.top();
            MaxHeap.pop();
            
            if(Freq > 1)
            {
                return "";
            }
            Result += C;
        }
        
        return Result;
    }
};