class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int Drink = 0;
        int Empty = 0;
        while(numBottles > 0)
        {
            Empty += numBottles;
            Drink += numBottles;
            numBottles = 0;

            if(Empty / numExchange >= 1)
            {
                numBottles = Empty / numExchange;
                Empty %= numExchange;
            }
        }
        return Drink;
    }
};