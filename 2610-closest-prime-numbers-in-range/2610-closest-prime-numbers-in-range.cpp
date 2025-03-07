class Solution {
public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> PrimeNums;
        int MinDiffer = INT_MAX;
        int MinIndex = 0;
        int Index = 0;

        left = (left == 1) ? 2 : left;

        for(int Num = left; Num <= right; Num++)
        {
            if(IsPrimeNumber(Num) == false)
                continue;

            PrimeNums.push_back(Num);
            if(PrimeNums.size() >= 2)
            {
                int Differ = PrimeNums[Index + 1] - PrimeNums[Index];
                if(Differ < MinDiffer)
                {
                    MinDiffer = Differ;
                    MinIndex = Index;
                }
                Index++;
            }
        }

        if(PrimeNums.size() < 2)
        {
            return {-1, -1};
        }

        vector<int> Result = {PrimeNums[MinIndex], PrimeNums[MinIndex + 1]};
        return Result;
    }

    bool IsPrimeNumber(const int Num)
    {
        for(int i = 2; i * i <= Num; i++)
        {
            if(Num % i == 0)
                return false;
        }
        return true;
    }
};