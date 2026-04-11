class Solution {
public:
    int minimumDistance(vector<int>& nums)
    {
        vector<vector<int>> Table(100001);
        const int N = nums.size();

        for(int i = 0; i < N; i++)
        {
            Table[nums[i]].push_back(i);
        }

        int Result = INT_MAX;
        for(vector<int>& Indices : Table)
        {
            if(Indices.size() < 3)
                continue;

            const int Range = Indices.size();
            for(int i = 0; i <= Range - 3; i++)
            {
                int I = Indices[i];
                int J = Indices[i + 1];
                int K = Indices[i + 2];

                int Sum = abs(I - J) + abs(J - K) + abs(K - I);
                Result = min(Result, Sum);
            }
        }
        return (Result == INT_MAX) ? -1 : Result;
    }
};