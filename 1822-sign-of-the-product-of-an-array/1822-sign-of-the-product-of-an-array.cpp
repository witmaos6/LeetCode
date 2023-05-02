class Solution {
public:
    int arraySign(vector<int>& nums)
    {
        int CountNegative = 0;
        
        for(int& Num : nums)
        {
            if(Num == 0)
            {
                return 0;
            }
            else if(Num < 0)
            {
                CountNegative++;
            }
        }
        
        if(CountNegative & 1)
        {
            return -1;
        }
        return 1;
    }
};