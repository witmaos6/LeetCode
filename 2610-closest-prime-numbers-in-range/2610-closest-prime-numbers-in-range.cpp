class Solution {
public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<bool> IsPrime(right + 1, true);
        IsPrime[0] = false;
        IsPrime[1] = false;

        for(int i = 2; i * i <= right; i++)
        {
            if(IsPrime[i])
            {
                for(int j = i * i; j <= right; j += i)
                {
                    IsPrime[j] = false;
                }
            }
        }

        vector<int> PrimeNums;
        for(int i = left; i <= right; i++)
        {
            if(IsPrime[i])
            {
                PrimeNums.push_back(i);
            }
        }

        if(PrimeNums.size() < 2)
        {
            return {-1, -1};
        }

        int MinDiffer = INT_MAX;
        vector<int> Result(2, -1);
        for(int i = 1; i < PrimeNums.size(); i++)
        {
            int Differ = PrimeNums[i] - PrimeNums[i - 1];
            if(Differ < MinDiffer)
            {
                MinDiffer = Differ;
                Result[0] = PrimeNums[i - 1];
                Result[1] = PrimeNums[i];
            }
        }
        return Result;
    }
};