class Solution {
public:
    int maxSum(vector<int>& nums)
    {
        int Max = INT_MIN;
        unordered_map<int, bool> Table;
        int Sum = 0;

        for(int& Num : nums)
        {
            if(Table.count(Num) == 0)
            {
                if(Num >= 0)
                {
                    Sum += Num;
                }
                else
                {
                    Max = max(Max, Num);
                }
            }
            Table[Num] = true;
        }
        if(Sum == 0 && Table.count(0) == 0)
        {
            return Max;
        }
        return Sum;
    }
};