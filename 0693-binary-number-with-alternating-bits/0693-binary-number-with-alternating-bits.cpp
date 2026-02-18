class Solution {
public:
    bool hasAlternatingBits(int n)
    {
        int Prev = -1;

        while(n > 0)
        {
            int Bit = n % 2;
            if(Bit == Prev)
                return false;
            
            Prev = Bit;
            n >>= 1;
        }
        return true;
    }
};