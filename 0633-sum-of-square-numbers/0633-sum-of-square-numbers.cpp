class Solution {
public:
    bool judgeSquareSum(int c)
    {
        for(int Divisor = 2; Divisor * Divisor <= c; Divisor++)
        {
            if(c % Divisor == 0)
            {
                int Exponent = 0;
                while(c % Divisor == 0)
                {
                    Exponent++;
                    c /= Divisor;
                }
                
                if(Divisor % 4 == 3 && Exponent % 2 != 0)
                    return false;
            }
        }
        
        return (c % 4 != 3);
    }
};