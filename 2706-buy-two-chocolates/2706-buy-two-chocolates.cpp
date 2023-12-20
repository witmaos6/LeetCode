class Solution {
public:
    int buyChoco(vector<int>& prices, int money)
    {
        pair<int, int> MinPair = {100,100};
        
        for(int Price : prices)
        {
            if(MinPair.first >= Price)
            {
                MinPair.second = MinPair.first;
                MinPair.first = Price;
            }
            else if(MinPair.second > Price)
            {
                MinPair.second = Price;
            }
        }
        
        int PurchasePrice = MinPair.first + MinPair.second;
        
        if(PurchasePrice <= money)
        {
            return money - PurchasePrice;
        }
        return money;
    }
};