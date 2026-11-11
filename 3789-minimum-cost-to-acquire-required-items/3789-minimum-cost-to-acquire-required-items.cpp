class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2)
    {
        if(need1 == 0 && need2 == 0)
            return 0;

        long long Result = LLONG_MAX;
        long long X = 0;

        long long V1 = X * costBoth + (long long)need1 * cost1 + (long long)need2 * cost2;
        Result = min(Result, V1);

        X = min(need1, need2);
        long long V2 = X * costBoth + ((long long)need1 - X) * cost1 + ((long long)need2 - X) * cost2;
        Result = min(Result, V2);

        X = max(need1, need2);
        long long V3 = X * (costBoth + max(0LL, need1 - X) * (long long)cost1 + max(0LL, need2 - X) * (long long)cost2);
        Result = min(Result, V3);

        return Result;
    }
};