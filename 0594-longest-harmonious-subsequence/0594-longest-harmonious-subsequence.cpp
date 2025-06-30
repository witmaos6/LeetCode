class Solution {
public:
    int findLHS(vector<int>& nums)
    {
        unordered_map<int, int> Table;
        for(int& Num : nums)
        {
            Table[Num]++;
        }

        int MaxLength = 0;

        for(auto&[Num, Freq] : Table)
        {
            if(Table.count(Num + 1))
            {
                int CurrLength = Freq + Table[Num + 1];
                MaxLength = max(MaxLength, CurrLength);
            }
        }
        return MaxLength;
    }
};