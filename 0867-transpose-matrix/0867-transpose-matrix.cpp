class Solution {
    int RowSize = 0;
    int ColSize = 0;
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix)
    {
        RowSize = static_cast<int>(matrix.size());
        ColSize = static_cast<int>(matrix[0].size());
        
        if(RowSize == ColSize)
        {
            for(int Row = 0; Row < RowSize; Row++)
            {
                for(int Col = Row + 1; Col < ColSize; Col++)
                {
                    swap(matrix[Row][Col], matrix[Col][Row]);
                }
            }
            return matrix;
        }
        
        return GetTransposeMatrix(matrix);
    }
    
private:
    vector<vector<int>> GetTransposeMatrix(const vector<vector<int>>& Matrix)
    {
        vector<vector<int>> TransposeMatrix(ColSize, vector<int>(RowSize));
        
        for(int Row = 0; Row < RowSize; Row++)
        {
            for(int Col = 0; Col < ColSize; Col++)
            {
                TransposeMatrix[Col][Row] = Matrix[Row][Col];
            }
        }
        
        return TransposeMatrix;
    }
};