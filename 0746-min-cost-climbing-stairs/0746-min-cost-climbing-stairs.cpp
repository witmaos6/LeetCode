class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        const int N = static_cast<int>(cost.size());
        vector<int> Memo(N + 1);
        
        for(int i = 2; i <= N; i++)
        {
            int Prev1 = Memo[i - 1] + cost[i - 1];
            int Prev2 = Memo[i - 2] + cost[i - 2];
            
            Memo[i] = min(Prev1, Prev2);
        }
        
        return Memo[N];
    }
};