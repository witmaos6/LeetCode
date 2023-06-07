class Solution {
public:
    int minFlips(int a, int b, int c)
    {
        int CountFlips = 0;
        
        while(a || b || c)
        {
            if(c & 1)
            {
                if(!(a & 1) && !(b & 1))
                    CountFlips++;
            }
            else
            {
                if(a & 1)
                    CountFlips++;
                
                if(b & 1)
                    CountFlips++;
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return CountFlips;
    }
};