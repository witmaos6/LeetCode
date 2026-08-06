class Solution {
public:
    int smallestNumber(int n, int t)
    {
        int Result = n;
        while(1)
        {
            int Prod = 1;
            int X = Result;

            while(X > 0)
            {
                Prod *= X % 10;
                X /= 10;
            }
            if(Prod % t == 0)
                break;
            
            Result++;
        }
        return Result;
    }
};