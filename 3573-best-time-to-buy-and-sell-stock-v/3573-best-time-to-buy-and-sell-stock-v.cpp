struct Stock
{
    long long MaxProfit;
    long long BuyHold;
    long long SellHold;
    Stock(long long P = 0, long long B = 0, long long S = 0) : MaxProfit(P), BuyHold(B), SellHold(S) {}
};

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k)
    {
        const int FirstPrice = prices[0];
        vector<Stock> Memo(k + 1, Stock(0, -FirstPrice, FirstPrice));
        const int N = static_cast<int>(prices.size());

        for(int Day = 1; Day < N; Day++)
        {
            const int CurrPrice = prices[Day];

            for(int Trans = k; Trans > 0; Trans--)
            {
                auto& [Profit, Buy, Sell] = Memo[Trans];

                const long long PrevProfit = Memo[Trans - 1].MaxProfit;

                Profit = max(Profit, max(Buy + CurrPrice, Sell - CurrPrice));
                Buy = max(Buy, PrevProfit - CurrPrice);
                Sell = max(Sell, PrevProfit + CurrPrice);
            }
        }

        return Memo[k].MaxProfit;
    }
};