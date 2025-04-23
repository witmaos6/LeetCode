class Solution {
public:
    int countLargestGroup(int n)
    {
        unordered_map<int, int> Table;
        int MaxSize = 0;
        for(int i = 1; i <= n; i++)
        {
            int Sum = DigitSum(i);
            Table[Sum]++;
            MaxSize = max(MaxSize, Table[Sum]);
        }

        int Count = 0;
        for(auto& [Sum, Size] : Table)
        {
            if(Size == MaxSize)
            {
                Count++;
            }
        }
        return Count;
    }
private:
    int DigitSum(int Num)
    {
        int Sum = 0;
        while(Num > 0)
        {
            Sum += (Num % 10);
            Num /= 10;
        }
        return Sum;
    }
};