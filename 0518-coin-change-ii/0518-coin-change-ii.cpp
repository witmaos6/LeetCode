class Solution {
public:
    int change(int Amount, vector<int>& Coins)
    {
        vector<int> Memo(Amount + 1);
        Memo[0] = 1;
        
        for(int& Coin : Coins)
        {
            for(int i = Coin; i <= Amount; i++)
            {
                Memo[i] += Memo[i - Coin];
            }
        }
        
        return Memo[Amount];
    }
};