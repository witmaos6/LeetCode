class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        unordered_map<int, int> Table;
        
        for(int& Num : nums)
        {
            Table[Num]++;
        }
        
        int Count = 0;
        
        for(pair<const int, int>& E : Table)
        {
            if(k == 0)
            {
                if(E.second > 1)
                {
                    Count++;
                }
            }
            else if(Table.find(E.first + k) != Table.end())
            {
                Count++;
            }
        }
        
        return Count;
    }
};