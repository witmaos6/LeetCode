class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange)
    {        
        int RemainBottles = (numBottles - 1) / (numExchange - 1);
        return numBottles + RemainBottles;
    }
};