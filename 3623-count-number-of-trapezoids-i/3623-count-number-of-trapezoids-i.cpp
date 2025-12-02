class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points)
    {
        const int Mod = 1e9 + 7;
        const int N = static_cast<int>(points.size());

        unordered_map<int, int> Freq;
        Freq.reserve(N);

        for(vector<int>& Point : points)
        {
            Freq[Point[1]]++;
        }

        long long Sum = 0;
        long long Count = 0;

        for(auto& [Y, F] : Freq)
        {
            if(F <= 1)
                continue;
            
            const long long C = F * (F - 1LL) / 2LL;
            Sum += C;
            Count += C * C;
        }

        long long Result = Sum * Sum - Count;
        Result = (Result / 2) % Mod;
        return Result;
    }
};