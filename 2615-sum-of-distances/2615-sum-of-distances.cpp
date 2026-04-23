class Solution {
public:
    vector<long long> distance(vector<int>& nums)
    {
        unordered_map<int, vector<int>> Table;
        const int N = nums.size();
        for(int i = 0; i < N; i++)
        {
            Table[nums[i]].push_back(i);
        }

        vector<long long> Result(N);
        for(auto& [Num, Indices] : Table)
        {
            const int Size = Indices.size();
            if(Size == 1)
                continue;
            
            vector<long long> Sum(Size + 1);
            for(int i = 0; i < Size; i++)
            {
                Sum[i + 1] = Sum[i] + Indices[i];
            }

            for(int i = 0; i < Size; i++)
            {
                Result[Indices[i]] = Sum.back() - 2LL * Sum[i] - (Size - 2LL * i) * Indices[i];
            }
        }

        return Result;
    }
};