class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        map<int, int> Table;
        for(int& cost : costs)
        {
            Table[cost]++;
        }

        int Result = 0;

        for(auto& [Cost, Count] : Table)
        {
            if(Count > 0)
            {
                if(Cost <= coins)
                {
                    int BuyCount = min(Count, (coins / Cost));

                    coins -= (Cost * BuyCount);
                    Result += BuyCount;
                }
                else
                {
                    break;
                }
            }
        }
        return Result;
    }
};