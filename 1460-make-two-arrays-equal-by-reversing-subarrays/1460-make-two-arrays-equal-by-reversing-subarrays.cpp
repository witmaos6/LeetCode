class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr)
    {
        unordered_map<int, int> Table;
        
        for(int Num : target)
        {
            Table[Num]++;
        }
        
        for(int Num : arr)
        {
            if(Table.find(Num) == Table.end())
            {
                return false;
            }
            Table[Num]--;
        }
        
        for(auto&[Num, Freq] : Table)
        {
            if(Freq != 0)
            {
                return false;
            }
        }
        
        return true;
    }
};