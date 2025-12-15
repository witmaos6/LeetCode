class Solution {
public:
    long long getDescentPeriods(vector<int>& prices)
    {
        long long Result = 0;
        int Prev = -1;
        long long Count = 1;
        for(int& Price : prices)
        {
            if(Prev== Price + 1)
            {
                Count++;
            }
            else
            {
                Count = 1;
            }
            Result += Count;
            Prev = Price;
        }
        return Result;
    }
};