class Solution {
public:
    long long coloredCells(int n)
    {
        long long N = n;
        return 1 + 2 * (N - 1) * N;
    }
};