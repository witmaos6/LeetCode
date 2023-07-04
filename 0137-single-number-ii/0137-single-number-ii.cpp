class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        unordered_map<int, int> Table;
        
        for(int& Num : nums)
        {
            Table[Num]++;
        }
        
        int Result = 0;
        for(pair<const int, int>& E : Table)
        {
            if(E.second == 1)
            {
                Result = E.first;
                break;
            }
        }
        return Result;
    }
};