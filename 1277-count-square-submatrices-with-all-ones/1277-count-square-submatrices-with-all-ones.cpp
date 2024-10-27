class Solution {
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        const int Rows = static_cast<int>(matrix.size());
        const int Cols = static_cast<int>(matrix[0].size());
        
        int Count = 0;
        for(int Row = 0; Row < Rows; ++Row)
        {
            for(int Col = 0; Col < Cols; ++Col)
            {
                if (Row > 0 && Col > 0 && matrix[Row][Col] > 0)
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