class Solution {
public:
    int sumFourDivisors(vector<int>& nums)
    {
        int Result = 0;
        for(int& Num : nums)
        {
            vector<int> Divisors;
            for(int i = 1; i * i <= Num; i++)
            {
                if(Num % i == 0)
                {
                    Divisors.push_back(i);
                    if(i != Num / i)
                    {
                        Divisors.push_back(Num / i);
                    }
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