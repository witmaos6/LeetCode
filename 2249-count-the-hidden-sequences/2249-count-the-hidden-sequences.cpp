class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper)
    {
        long Sum = 0;
        long MaxNum = 0;
        long MinNum = 0;
        for(int& Num : differences)
        {
            Sum += Num;
            MaxNum = max(MaxNum, Sum);
            MinNum = min(MinNum, Sum);
        }
        return max(0L, upper - lower - MaxNum + MinNum + 1);
    }
};