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
        string Str = to_string(N);
        for(char& C : Str)
        {
            if(C == '0')
            {
                return true;
            }
        }
        return false;
    }
};