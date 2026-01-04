class Solution {
public:
    int sumFourDivisors(vector<int>& nums)
    {
        int Result = 0;
        for(int& Num : nums)
        {
            int Count = 0;
            int Sum = 0;
            for(int i = 1; i * i <= Num; i++)
            {
                if(Num % i == 0)
                {
                    Count++;
                    Sum += i;
                    if(i != Num / i)
                    {
                        Count++;
                        Sum += Num / i;
                    }
                }
            }
            if(Count == 4)
            {
                Result += Sum;
            }
        }
        return Result;
    }
};