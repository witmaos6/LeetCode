class Solution {
public:
    int minimumDistance(vector<int>& nums)
    {
        unordered_map<int, vector<int>> Table;
        const int N = nums.size();

        int Result = INT_MAX;
        for(int i = 0; i < N; i++)
        {
            vector<int>& Indices = Table[nums[i]];
            Indices.push_back(i);

            if(Indices.size() >= 3)
            {
                const int M = Indices.size();
                int I = Indices[M - 3];
                int J = Indices[M - 2];
                int K = Indices[M - 1];

                int Sum = abs(I - J) + abs(J - K) + abs(K - I);
                Result = min(Result, Sum);
            }
        }

        return (Result == INT_MAX) ? -1 : Result;
    }
};