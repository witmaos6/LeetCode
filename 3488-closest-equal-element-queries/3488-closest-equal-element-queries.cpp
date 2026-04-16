class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries)
    {
        unordered_map<int, vector<int>> Table;
        const int N = nums.size();

        for(int i = 0; i < N; i++)
        {
            Table[nums[i]].push_back(i);
        }

        vector<int> Result;
        Result.reserve(queries.size());

        for(int& Query : queries)
        {
            int Num = nums[Query];

            vector<int>& Indices = Table[Num];
            int Range= Indices.size();

            if(Range == 1)
            {
                Result.push_back(-1);
                continue;
            }
            
            int IndexQ = lower_bound(Indices.begin(), Indices.end(), Query) - Indices.begin();

            int Dist = N - 1;
            int J = Indices[IndexQ];

            if(IndexQ + 1 != Range)
            {
                Dist = min(Dist, Indices[IndexQ + 1] - J);
            }
            else
            {
                Dist = min(Dist, N + Indices[0] - J);
            }

            if(IndexQ != 0)
            {
                Dist = min(Dist, J - Indices[IndexQ - 1]);
            }
            else
            {
                Dist = min(Dist, N + J - Indices.back());
            }

            Result.push_back(Dist);
        }
        return Result;
    }
};