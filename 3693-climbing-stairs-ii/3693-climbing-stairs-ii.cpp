class Solution {
public:
    int climbStairs(int n, vector<int>& costs)
    {
        vector<int> Memo(n + 1, INT_MAX);
        Memo[n] = 0;
        array<int, 3> D = {1,4,9};
        for(int i = n; i >= 0; i--)
        {
            int Range = max(0, i - 3);
            int Index = -1;
            for(int j = i - 1; j >= Range; j--)
            {
                Index++;
                int Value = costs[i - 1] + D[Index];
                Memo[j] = min(Memo[j], Memo[i] + Value);
            }
        }
        return Memo[0];
    }
};