class Solution {
public:
    int minimumCost(vector<int>& cost)
    {
        sort(cost.begin(), cost.end(), greater<int>());
        const int N = cost.size();
        int MinCost = 0;

        for(int i = 0; i < N; i += 3)
        {
            MinCost += cost[i];
            if(i + 1 < N)
            {
                MinCost += cost[i + 1];
            }
        }
        return MinCost;
    }
};