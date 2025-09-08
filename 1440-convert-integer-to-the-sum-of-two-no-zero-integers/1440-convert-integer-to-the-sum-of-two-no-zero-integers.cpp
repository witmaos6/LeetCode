class Solution {
public:
    vector<int> getNoZeroIntegers(int n)
    {
        vector<int> Result(2);
        
        for(int i = 1; i < n; i++)
        {    
            int B = n - i;
            if(!ContainZero(i) && !ContainZero(B))
            {
                Result[0] = i;
                Result[1] = B;
            }
        }

        return Result;
    }

    bool ContainZero(int N)
    {
        if(N == 0)
            return true;
        while(N > 0)
        {
            int Digit = N % 10;
            if(Digit == 0)
                return true;

            N /= 10;
        }
        return false;
    }
};