class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins)
    {
        sort(costs.begin(), costs.end());
        int Count = 0;

        for(int& Cost : costs)
        {
            if(coins >= Cost)
            {
                coins -= Cost;
                Count++;
            }
            else
            {
                break;
            }
        }
        return Count;
    }
};