class Solution {
public:
    vector<int> finalPrices(vector<int>& prices)
    {
        const int N = static_cast<int>(prices.size());
        stack<int> Monotonic;
        for(int i = N - 1; i >= 0; i--)
        {
            while(!Monotonic.empty() && Monotonic.top() > prices[i])
            {
                Monotonic.pop();
            }
            
            int Temp = prices[i];
            if(!Monotonic.empty())
            {
                prices[i] -= Monotonic.top();
            }
            Monotonic.push(Temp);
        }

        return prices;
    }
};