class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int N = static_cast<int>(prices.size());
        int Buying = 0, Selling = -prices[0];
        
        for(int i = 1; i < N; i++)
        {
            Buying = max(Buying, Selling + prices[i] - fee);
            Selling = max(Selling, Buying - prices[i]);
        }
        
        return Buying;
    }
};