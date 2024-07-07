class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int EmptyBottle = 0;
        int Drink = 0;
        
        while(numBottles > 0)
        {
            Drink += numBottles;
            EmptyBottle += numBottles;
            numBottles = EmptyBottle / numExchange;
            EmptyBottle = EmptyBottle % numExchange;
            
        }
        
        return Drink;
    }
};