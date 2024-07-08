class Solution {
public:
    int findTheWinner(int n, int k)
    {
        int Result = 0;
        for(int i = 2; i <= n; i++)
        {
            Result = (Result + k) % i;
        }
        return Result + 1;
    }
};