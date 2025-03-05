class Solution {
public:
    long long coloredCells(int n)
    {
        if(n == 1)
        {
            return 1;
        }
        long long Result = 1;
        for(int i = 2; i <= n; i++)
        {
            long long AddCell = i;
            Result += (AddCell * 2) + 2 * (AddCell - 2);
        }
        return Result;
    }
};