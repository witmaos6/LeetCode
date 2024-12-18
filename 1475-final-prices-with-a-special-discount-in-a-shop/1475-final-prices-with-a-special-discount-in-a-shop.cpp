class Solution {
public:
    vector<int> finalPrices(vector<int>& prices)
    {
        const int N = static_cast<int>(prices.size());
        for(int i = 0; i < N - 1; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                if(prices[i] >= prices[j])
                {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        
        return prices;
    }
};