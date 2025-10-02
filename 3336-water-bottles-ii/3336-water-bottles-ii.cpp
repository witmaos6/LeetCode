class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int Empty = 0;
        int Result = 0;
        while(numBottles > 0)
        {
            Empty += numBottles;
            Result += numBottles;
            numBottles = 0;

            while(Empty >= numExchange)
            {
                Empty -= numExchange;
                numExchange++;
                numBottles++;
            }
        }
        return Result;
    }
};