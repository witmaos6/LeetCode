class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k)
    {
        long long Sum = 0;

        for(int candy : candies)
        {
            Sum += candy;
        }

        long long Low = 1, High = Sum / k;
        long long Result = 0;

        while(Low <= High)
        {
            long long GetPile = (High + Low) / 2;

            if(AllocateCandies(candies, k, GetPile))
            {
                Result = GetPile;
                Low = GetPile + 1;
            }
            else
            {
                High = GetPile - 1;
            }
        }

        return Result;
    }

private:
    bool AllocateCandies(vector<int>& candies, long long k, long long GetPile)
    {
        long long Split = 0;
        for(int candy : candies)
        {
            Split += candy / GetPile;
        }

        return Split >= k;
    }
};