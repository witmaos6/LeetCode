class Solution {
public:
    bool isMonotonic(vector<int>& nums)
    {
        int Increasing = nums[0];
        int Decreasing = nums[0];
        bool FlagIncreasing = true;
        bool FlagDecreasing = true;
        
        for(int Num : nums)
        {
            if(Increasing <= Num)
            {
                Increasing = Num;
            }
            else
            {
                FlagIncreasing = false;
            }
            
            if(Decreasing >= Num)
            {
                Decreasing = Num;
            }
            else
            {
                FlagDecreasing = false;
            }
        }
        
        return FlagIncreasing || FlagDecreasing;
    }
};