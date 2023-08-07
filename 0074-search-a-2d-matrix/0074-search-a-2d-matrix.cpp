class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int RowSize = static_cast<int>(matrix.size());
        int ColSize = static_cast<int>(matrix[0].size());
        
        int Left = 0, Right = RowSize * ColSize - 1;
        
        while(Left <= Right)
        {
            int Middle = (Right + Left) / 2;
            int MidValue = matrix[Middle / ColSize][Middle % ColSize];
            
            if(MidValue == target)
            {
                return true;
            }
            else if(MidValue > target)
            {
                Right = Middle - 1;
            }
            else
            {
                Left = Middle + 1;
            }
        }
        
        return false;
    }
};