class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time)
    {
        const int N = static_cast<int>(cost.size());
        vector<int> Memo(N + 1, 1e9);
        Memo[0] = 0;
        
        for(int i = 0; i < N; i++)
        {
            for(int j = N; j > 0; j--)
            {
                int Index = max(j - time[i] - 1, 0);
                int CurrCost = Memo[Index] + cost[i];
                
                Memo[j] = min(Memo[j], CurrCost);
            }
        }
        
        return Memo[N];
    }
};