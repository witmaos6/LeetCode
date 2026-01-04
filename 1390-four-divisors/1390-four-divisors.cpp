class Solution {
public:
    int sumFourDivisors(vector<int>& nums)
    {
        int Result = 0;
        for(int& Num : nums)
        {
            int Count = 0;
            set<int> Divisors;
            for(int i = 1; i * i <= Num; i++)
            {
                if(Num % i == 0)
                {
                    Count += 2;
                    Divisors.insert(i);
                    Divisors.insert(Num / i);
                }
            }
            if(Divisors.size() == 4)
            {
                int Sum = accumulate(Divisors.begin(), Divisors.end(), 0);
                Result += Sum;
            }
        }
        return Result;
    }
};