class Solution {
public:
    int minScoreTriangulation(vector<int>& values)
    {
        const int N = static_cast<int>(values.size());
        if(N == 3)
            return values[0] * values[1] * values[2];

        vector<vector<int>> Memo(N - 1, vector<int>(N));

        for(int d = 2; d <= N - 1; d++)
        {
            for(int i = 0; i < N - d; i++)
            {
                const int j = i + d;
                int W = INT_MAX, E = values[i] * values[j];
                for(int k = i + 1; k < j; k++)
                {
                    W = min(W, E * values[k] + Memo[i][k] + Memo[k][j]);
                }
                Memo[i][j] = W;
            }
        }
        return Memo[0][N - 1];
    }
};