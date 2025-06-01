class Solution {
public:
    long long distributeCandies(int n, int limit)
    {
        long long Result = 0;
        return CombiCount(n) - 3 * CombiCount(n - (limit + 1)) + 3 * CombiCount(n - 2 * (limit + 1)) - CombiCount(n - 3 * (limit + 1));
    }
private:
    long long CombiCount(int Sum)
    {
        if(Sum < 0)
            return 0;

        return 1LL * (Sum + 2) * (Sum + 1) / 2;
    }
};