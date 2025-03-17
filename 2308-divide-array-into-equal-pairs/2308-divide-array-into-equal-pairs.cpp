class Solution {
public:
    bool divideArray(vector<int>& nums)
    {
        array<bool, 501> Table;
        for(int& Num : nums)
        {
            Table[Num] = !Table[Num];
        }

        for(bool Check : Table)
        {
            if(Check)
                return false;
        }
        return true;
    }
};