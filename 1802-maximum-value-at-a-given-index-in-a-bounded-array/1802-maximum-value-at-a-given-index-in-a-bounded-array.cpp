class Solution {
public:
    int maxValue(int n, int index, int maxSum)
    {
        int Low = 1, High = maxSum;
        
        int Right = n - index - 1;
        int Left = index;
        
        long Result = 0;
        
        while(Low <= High)
        {
            int Middle = (High + Low) / 2;
            
            long M = Middle - 1;
            
            long RightSum = GetSideSum(M, Right);
            long LeftSum = GetSideSum(M, Left);
            
            long Sum = Middle + RightSum + LeftSum;
            
            if(Sum <= maxSum)
            {
                Result = Middle;
                Low = Middle + 1;
            }
            else
            {
                High = Middle - 1;
            }
        }
        
        return Result;
    }
    
private:
    long GetSideSum(long Middle, long Side)
    {
        long Result = GetAllSum(Middle);
        if(Side <= Middle)
        {
            Result -= GetAllSum(Middle - Side);
        }
        else
        {
            Result += (Side - Middle);
        }
        
        return Result;
    }
    
    long GetAllSum(long Range)
    {
        return (Range + 1) * Range / 2;
    }
};