class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> Result(n + 1);
        if(n == 0)
        {
            return Result;
        }
        else if(n >= 1)
        {
            Result[1] = 1;
        }
        
        int Prev = 1;
        int i = 2;
        
        while(i <= n)
        {
            int j = Prev;
            int Range = Prev * 2;
            
            while(j < Range && i <= n)
            {
                Result[i] = Result[j];
                i++;
                j++;
            }
            while(Prev < Range && i <= n)
            {
                Result[i] = Result[Prev] + 1;
                Prev++;
                i++;
            }
        }
        return Result;
    }
};