class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        int MaxCost = *max_element(costs.begin(), costs.end());

        vector<int> CountCost(MaxCost + 1);

        for(int& cost : costs)
        {
            CountCost[cost]++;
        }

        int CanBuyIcecream = 0;

        for(int cost = 1; cost < MaxCost + 1; cost++)
        {
            if(CountCost[cost] > 0)
            {
                if(cost <= coins)
                {
                    int Count = min(CountCost[cost], (coins / cost));

                    coins -= (cost * Count);
                    CanBuyIcecream += Count;
                }
                else
                {
                    break;
                }
            }
            
        }

        return CanBuyIcecream;
    }
};