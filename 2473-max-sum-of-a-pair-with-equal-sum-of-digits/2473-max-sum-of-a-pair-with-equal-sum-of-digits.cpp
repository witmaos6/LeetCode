class Solution {
    using Pair = pair<int, int>;
public:
    int maximumSum(vector<int>& nums)
    {
        unordered_map<int, Pair> DigitSumToPair;
        int MaxSum = -1;
        
        for(int& Num : nums)
        {
            int DigitSum = GetDigitSum(Num);

            if(DigitSumToPair.find(DigitSum) == DigitSumToPair.end())
            {
                DigitSumToPair[DigitSum] = {Num, 0};
            }
            else
            {
                Pair& P = DigitSumToPair[DigitSum];
                SetLargestPair(Num, P);

                int CurrSum = P.first + P.second;
                MaxSum = max(MaxSum, CurrSum);
            }
        }

        return MaxSum;
    }

private:
    int GetDigitSum(int Num)
    {
        int Sum = 0;
        while(Num > 0)
        {
            Sum += (Num % 10);
            Num /= 10;
        }
        return Sum;
    }

    void SetLargestPair(int a, Pair& P)
    {
        int b = P.first;
        int c = P.second;
        if (a > c) std::swap(a, c);
        if (a > b) std::swap(a, b);
        if (b > c) std::swap(b, c);
        P.first = b;
        P.second = c;
    }
};