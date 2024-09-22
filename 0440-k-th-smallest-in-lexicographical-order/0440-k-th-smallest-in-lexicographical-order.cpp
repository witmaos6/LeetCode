class Solution {
public:
    int findKthNumber(int n, int k)
    {
        int CurrPrefix = 1;
        --k;
        
        while (k > 0)
        {
            int Count = CountNumbersWithPrefix(CurrPrefix, n);
            
            if (k >= Count)
            {
                ++CurrPrefix;
                k -= Count;
            }
            else
            {
                CurrPrefix *= 10;
                --k;
            }
        }
        
        return CurrPrefix;
    }

private:
    int CountNumbersWithPrefix(int Prefix, int N)
    {
        long long FirstNumber = Prefix;
        long long NextNumber = Prefix + 1;
        int TotalCount = 0;

        while (FirstNumber <= N)
        {
            long long Temp = min(1LL + N, NextNumber);
            
            TotalCount += static_cast<int>(Temp - FirstNumber);
            FirstNumber *= 10;
            NextNumber *= 10;
        }

        return TotalCount;
    }
};