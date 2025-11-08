class Solution {
public:
    int minimumOneBitOperations(int n)
    {
        int Result = 0;
        
        while(n > 0)
        {
            Result ^= n;
            n >>= 1;
        }
        
        return Result;
    }
};