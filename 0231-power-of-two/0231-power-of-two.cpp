class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        bitset<32> NBit(n);
        
        if(n > 0 && NBit.count() == 1)
        {
            return true;
        }
        return false;
    }
};