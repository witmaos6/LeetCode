class Solution {
public:
    int missingMultiple(vector<int>& nums, int k)
    {
        vector<bool> Table(101);
        for(int& Num : nums)
        {
            Table[Num] = true;
        }

        int Last = 0;
        for(int i = 1; i * k <= 100; i++)
        {
            if(!Table[i * k])
            {
                return i * k;
            }
            Last = i;
        }

        return (Last + 1) * k;
    }
};