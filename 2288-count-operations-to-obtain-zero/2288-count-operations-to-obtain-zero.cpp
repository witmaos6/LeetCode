class Solution {
public:
    int countOperations(int num1, int num2)
    {
        int Max = max(num1, num2);
        int Min = min(num1, num2);
        int Count = 0;

        while(Max > 0 && Min > 0)
        {
            int Temp = Max - Min;
            Max = max(Temp, Min);
            Min = min(Temp, Min);
            Count++;
        }
        return Count;
    }
};