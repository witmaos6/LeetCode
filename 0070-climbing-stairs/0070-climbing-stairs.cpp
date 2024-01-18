class Solution {
public:
    int climbStairs(int n)
    {
        if(n <= 3)
        {
            return n;
        }
        int OneStep = 1;
        int TwoStep = 2;
        int Result = 0;
        
        for(int i = 3; i <= n; i++)
        {
            Result = OneStep + TwoStep;
            OneStep = TwoStep;
            TwoStep = Result;
        }
        return Result;
    }
};