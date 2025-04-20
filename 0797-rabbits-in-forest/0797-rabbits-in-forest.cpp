class Solution {
public:
    int numRabbits(vector<int>& answers)
    {
        unordered_map<int, int> Table;
        for(int& Num : answers)
        {
            Table[Num]++;
        }
        
        int Count = 0;
        for(auto&[Num, Answer] : Table)
        {
            Count += ceil((double)Answer / (Num + 1)) * (Num + 1);
        }
        return Count;
    }
};