class Solution {
    using Pair = pair<char, int>;
    const char Empty = '_';
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        array<int, 26> Table;
        for(char& C : s)
        {
            Table[C - 'a']++;
        }
        
        priority_queue<Pair, vector<Pair>> MaxHeap;
        for(int i = 0; i < 26; i++)
        {
            if(Table[i] > 0)
            {
                MaxHeap.emplace('a' + i, Table[i]);
            }
        }
        
        string Result;
        Pair Contain = {Empty, 0};
        while(!MaxHeap.empty())
        {
            auto[C, Freq] = MaxHeap.top();
            MaxHeap.pop();
            
            if(Contain.first != Empty)
            {
                Result += C;
                Freq--;
                
                MaxHeap.push(Contain);
                
                if(Freq > 0)
                {
                    MaxHeap.emplace(C, Freq);
                }
                
                Contain = {Empty, 0};
                continue;
            }
            
            int Range = min(repeatLimit, Freq);
            for(int i = 0; i < Range; i++)
            {
                Result += C;
            }
            Freq -= Range;
            
            if(Freq > 0)
            {
                Contain = {C, Freq};
            }
        }
        
        return Result;
    }
};