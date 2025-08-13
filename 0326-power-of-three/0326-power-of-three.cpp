class Solution {
public:
    bool isPowerOfThree(int n)
    {
        int Num = 0;
        for(int i = 0; pow(3, i) <= n; i++)
        {
            Num = pow(3, i);
            if(Num == n)
                return true;
        }
        
        return false;
    }
};