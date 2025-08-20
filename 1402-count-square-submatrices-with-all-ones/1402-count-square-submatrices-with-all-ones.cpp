class Solution {
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        const int Rows = static_cast<int>(matrix.size());
        const int Cols = static_cast<int>(matrix[0].size());
        
        int Count = 0;
        for(int Row = 0; Row < Rows; ++Row)
        {
            Count += matrix[Row][0];
        }
        for(int Col = 1; Col < Cols; ++Col)
        {
            Count += matrix[0][Col];
        }
        
        for(int Row = 1; Row < Rows; ++Row)
        {
            for(int Col = 1; Col < Cols; ++Col)
            {
                if (matrix[Row][Col] > 0)
                {
                    int MinAdj = min(matrix[Row - 1][Col], matrix[Row][Col - 1]);
                    matrix[Row][Col] = min(matrix[Row - 1][Col - 1], MinAdj) + 1;
                }
                Count += matrix[Row][Col];
            }
        }
        
        return Count;
    }
};