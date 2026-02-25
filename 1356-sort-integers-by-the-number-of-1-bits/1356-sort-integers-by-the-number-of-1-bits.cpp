class Solution {
    using Pair = pair<int, int>;
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        vector<Pair> Binaries;
        Binaries.reserve(arr.size());
        for(int& Num : arr)
        {
            int Binary = __builtin_popcount(Num);
            Binaries.emplace_back(Binary, Num);
        }
        
        sort(Binaries.begin(), Binaries.end());

        vector<int> Result;
        Result.reserve(arr.size());
        for(Pair& P : Binaries)
        {
            Result.push_back(P.second);
        }

        return Result;
    }
};