class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        int MaxInt = INT_MIN;
        unordered_set<int> Table;
        
        for(int Num : nums)
        {
            if(Table.find(-Num) != Table.end())
            {
                MaxInt = max(MaxInt, abs(Num));
            }
            Table.insert(Num);
        }
        return MaxInt == INT_MIN ? -1 : MaxInt;
    }
};