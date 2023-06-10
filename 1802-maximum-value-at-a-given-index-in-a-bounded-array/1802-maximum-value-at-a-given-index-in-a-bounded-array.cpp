class Solution {
public:
    int maxValue(int n, int index, int maxSum)
    {
        maxSum -= n;

        int Low = 0, High = maxSum;
        int R = n - 1 - index;

        while(Low < High)
        {
            int Middle = (Low + High + 1) / 2;

            long Left = max(0, Middle - index);
            long LeftSum = GetRangeSum(Left, Middle);

            long Right = max(0, Middle - R);
            long RightSum = GetRangeSum(Right, Middle);

            long Sum = LeftSum + RightSum - Middle;
            if(Sum > maxSum)
            {
                High = Middle - 1;
            }
            else
            {
                Low = Middle;
            }
        }

        return Low + 1;
    }
private:    
    long GetRangeSum(long Begin, long End)
    {
        return (End + Begin) * (End - Begin + 1) / 2;
    }
};