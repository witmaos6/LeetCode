class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        const int N = static_cast<int>(triangle.size());
        if(N == 1)
            return triangle[0][0];

        for(int i = 1; i < N; i++)
        {
            int M = static_cast<int>(triangle[i].size());
            triangle[i][0] += triangle[i - 1][0];

            for(int j = 1; j < M; j++)
            {
                int Top1 = triangle[i - 1][j - 1];
                int Top2 = (triangle[i - 1].size() > j) ? triangle[i - 1][j] : INT_MAX;

                int Min = min(Top1, Top2);
                triangle[i][j] += Min;
            }
        }

        int Result = INT_MAX;
        for(int& Num : triangle.back())
        {
            Result = min(Result, Num);
        }
        return Result;
    }
};