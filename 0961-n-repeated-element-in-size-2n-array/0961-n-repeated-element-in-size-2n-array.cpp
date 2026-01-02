class Solution {
public:
    int repeatedNTimes(vector<int>& nums)
    {
        unordered_set<int> Table;
        for(int& Num : nums)
        {
            if(Table.count(Num))
            {
                return Num;
            }
            Table.insert(Num);
        }
        return 0;
    }
};