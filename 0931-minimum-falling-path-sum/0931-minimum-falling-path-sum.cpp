class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        const int N = static_cast<int>(matrix.size());
        
        vector<vector<int>> Memo(N, vector<int>(N + 2, INT_MAX));
        for(int Col = 0; Col < N; Col++)
        {
            Memo[0][Col + 1] = matrix[0][Col];
        }
        
        for(int Row = 1; Row < N; Row++)
        {
            for(int Col = 1; Col <= N; Col++)
            {
                
                int MinPrevRow = min(Memo[Row - 1][Col - 1], min(Memo[Row - 1][Col], Memo[Row - 1][Col + 1]));
                Memo[Row][Col] = matrix[Row][Col - 1] + MinPrevRow;
            }
        }
        
        int MinSum = INT_MAX;
        for(int i = 1; i <= N; i++)
        {
            MinSum = min(MinSum, Memo[N - 1][i]);
        }
        return MinSum;
    }
};