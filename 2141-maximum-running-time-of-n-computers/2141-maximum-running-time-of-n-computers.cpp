class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries)
    {
        sort(batteries.begin(), batteries.end());

        long long Left = 1;
        long long Right = accumulate(batteries.begin(), batteries.end(), 0LL) / n;
        long long Result = 0;
        while(Left <= Right)
        {
            long long Mid = Left + (Right - Left) / 2;

            if(Possible(batteries, Mid, n))
            {
                Left = Mid + 1;
                Result = Mid;
            }
            else
            {
                Right = Mid - 1;
            }
        }
        return Result;
    }

private:
    bool Possible(vector<int>& Batteries, long long Mid, int N)
    {
        long long Sum = 0;
        for(int& Battery : Batteries)
        {
            Sum += Battery;
            if(Sum >= Mid)
            {
                Sum -= Mid;
                N--;
            }
            if(N == 0)
            {
                return true;
            }
        }
        return false;
    }
};