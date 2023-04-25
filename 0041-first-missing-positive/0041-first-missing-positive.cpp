class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        unordered_set<int> Table;
        
        for(int& num : nums)
        {
            if(num > 0)
            {
                Table.insert(num);
            }
        }
        
        int ExistMinValue = 1;
        
        for(int i = 1; i <= 100001; i++)
        {
            if(Table.find(i) == Table.end())
            {
                ExistMinValue = i;
                break;
            }
        }
        
        return ExistMinValue;
    }
};