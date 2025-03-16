class Solution {
    int MinR = 101;
    int MaxR = 0;
    array<int, 101> Freq;
public:
    long long repairCars(vector<int>& ranks, int cars)
    {
        for(int& R : ranks)
        {
            MinR = min(MinR, R);
            MaxR = max(MaxR, R);
            Freq[R]++;
        }

        long long L = 1;
        long long R = L * MinR * cars * cars;

        while(L < R)
        {
            long long Mid = (L + R) / 2;
            if(CanRepair(cars, Mid))
            {
                R = Mid;
            }
            else
            {
                L = Mid + 1;
            }
        }

        return L;
    }
private:
    bool CanRepair(int cars, long long Time)
    {
        long long Count = 0;

        for(int R = MinR; R <= MaxR; R++)
        {
            Count += Freq[R] * static_cast<long long>(sqrt(Time / R));
            if(Count >= cars)
                return true;
        }
        return Count >= cars;
    }
};