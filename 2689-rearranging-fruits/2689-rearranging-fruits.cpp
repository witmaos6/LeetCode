class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2)
    {
        unordered_map<int, int> Table;
        int MinCost = INT_MAX;
        const int N = static_cast<int>(basket1.size());
        for(int i = 0; i < N; i++)
        {
            Table[basket1[i]]++;
            Table[basket2[i]]--;
            MinCost = min({MinCost, basket1[i], basket2[i]});
        }

        vector<int> Swaps;
        for(auto& [Fruit, Diff] : Table)
        {
            if(Diff % 2 != 0)
                return -1;

            for(int i = 0; i < abs(Diff)/2; i++)
            {
                Swaps.push_back(Fruit);
            }
        }
        sort(Swaps.begin(), Swaps.end());

        long long Result = 0;
        const int M = static_cast<int>(Swaps.size());
        for(int i = 0; i < M/2; i++)
        {
            Result += min({MinCost * 2, Swaps[i]});
        }
        return Result;
    }
};