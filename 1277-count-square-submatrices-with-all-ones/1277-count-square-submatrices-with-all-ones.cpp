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
                if(matrix[Row][Col] == 1)
                {
                    int SubCount = 0;
                    int Range = min(Rows - Row, Cols - Col);
                    for(int Length = 1; Length <= Range; ++Length)
                    {
                        if(IsSquare(matrix, Row, Col, Length))
                        {
                            ++SubCount;
                        }
                    }
                    Count += SubCount;
                }
            }
        }
        
        return Count;
    }
    
private:
    bool IsSquare(const vector<vector<int>>& Matrix, int BeginRow, int BeginCol, const int Length)
    {
        const int RowBoundary = BeginRow + Length;
        const int ColBoundary = BeginCol + Length;
        
        for(int Row = BeginRow; Row < RowBoundary; ++Row)
        {
            for(int Col = BeginCol; Col < ColBoundary; ++Col)
            {
                if(Matrix[Row][Col] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};