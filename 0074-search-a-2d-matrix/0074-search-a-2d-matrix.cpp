class Solution {
    int RowSize = 0;
    int ColSize = 0;
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        RowSize = static_cast<int>(matrix.size());
        ColSize = static_cast<int>(matrix[0].size());
        
        int BoundaryRow = GetBoundaryRow(matrix, target);
        
        if(BoundaryRow >= RowSize)
        {
            return false;
        }
        
        return binary_search(matrix[BoundaryRow].begin(), matrix[BoundaryRow].end(), target);
    }
    
private:
    int GetBoundaryRow(vector<vector<int>>& Matrix, int Target)
    {
        int Left = 0, Right = RowSize;
        
        while(Left < Right)
        {
            int Middle = (Right + Left) / 2;
            
            if(Matrix[Middle].front() <= Target)
            {
                if(Matrix[Middle].back() >= Target)
                {
                    return Middle;
                }
                else
                {
                    Left = Middle + 1;
                }
            }
            else
            {
                Right = Middle - 1;
            }
        }
        
        return Left;
    }
};