class Solution {
public:
    bool judgeSquareSum(int c)
    {
        long A = 1;
        long B = sqrt(c);
        
        if(B * B == c)
            return true;
        
        while(A <= B)
        {
            long Sum = (A * A) + (B * B);
            
            if(Sum == c)
            {
                return true;
            }
            else if(Sum < c)
            {
                A++;
            }
            else
            {
                B--;
            }
        }
        
        return false;
    }
};