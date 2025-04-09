class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        unordered_set<int> Table;
        for(int& Num : nums)
        {
            if(Num < k)
                return -1;

            Table.insert(Num);
        }

        if(Table.find(k) == Table.end())
        {
            return Table.size();
        }
        return Table.size() - 1;
    }
};