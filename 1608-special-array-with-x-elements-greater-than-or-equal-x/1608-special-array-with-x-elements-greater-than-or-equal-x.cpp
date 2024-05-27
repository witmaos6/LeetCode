class Solution {
public:
    int specialArray(vector<int>& nums)
    {
        vector<int> Table(1001);
        
        for (int Num : nums)
        {
            Table[Num]++;
        }
        
        int Total = static_cast<int>(nums.size());
        
        for (int i = 0; i < 1001; i++)
        {
            if (i == Total)
            {
                return i;
            }
            Total -= Table[i];
        }
        
        return -1;
    }
};