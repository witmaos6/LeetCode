class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        const int RowSize = static_cast<int>(matrix.size());
        const int ColSize = static_cast<int>(matrix[0].size());
        
        vector<vector<int>> Memo(RowSize, vector<int>(ColSize + 2, INT_MAX));
        for(int Col = 0; Col < ColSize; Col++)
        {
            Memo[0][Col + 1] = matrix[0][Col];
        }
        
        for(int Row = 1; Row < RowSize; Row++)
        {
            for(int Col = 1; Col <= ColSize; Col++)
            {
                
                int MinPrevRow = min(Memo[Row - 1][Col - 1], min(Memo[Row - 1][Col], Memo[Row - 1][Col + 1]));
                Memo[Row][Col] = matrix[Row][Col - 1] + MinPrevRow;
            }
        }
        
        int MinSum = INT_MAX;
        for(int i = 1; i < ColSize + 1; i++)
        {
            MinSum = min(MinSum, Memo[RowSize - 1][i]);
        }
        return MinSum;
    }
};