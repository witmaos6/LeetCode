class Solution {
public:
    int findFinalValue(vector<int>& nums, int original)
    {
        vector<bool> Table(1001);

        for(int& Num : nums)
        {
            Table[Num] = true;
        }

        while(original <= Table.size() && Table[original])
        {
            original <<= 1;
        }
        return original;
    }
};