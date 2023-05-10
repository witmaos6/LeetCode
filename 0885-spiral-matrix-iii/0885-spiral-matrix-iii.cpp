class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {   
        vector<vector<int>> Matrix(rows * cols, vector<int>(2));
        Matrix[0] = {rStart, cStart};
        
        int RBegin = rStart - 1, REnd = rStart + 1;
        int CBegin = cStart - 1, CEnd = cStart + 1;
        int i = 1;
        
        while(i < rows * cols)
        {
            for(int Row = RBegin + 1; Row <= REnd; Row++)
            {
                if(bInBoundary(Row, CEnd, rows, cols))
                {
                    Matrix[i] = {Row, CEnd};
                    i++;
                }
            }
            
            for(int Col = CEnd - 1; Col >= CBegin; Col--)
            {
                if(bInBoundary(REnd, Col, rows, cols))
                {
                    Matrix[i] = {REnd, Col};
                    i++;
                }
            }
            
            for(int Row = REnd - 1; Row >= RBegin; Row--)
            {
                if(bInBoundary(Row, CBegin, rows, cols))
                {
                    Matrix[i] = {Row, CBegin};
                    i++;
                }
            }
            
            for(int Col = CBegin + 1; Col <= CEnd; Col++)
            {
                if(bInBoundary(RBegin, Col, rows, cols))
                {
                    Matrix[i] = {RBegin, Col};
                    i++;
                }
            }
            
            RBegin--;
            REnd++;
            CBegin--;
            CEnd++;
        }
        
        return Matrix;
    }
    
private:
    bool bInBoundary(int Row, int Col, int RowSize, int ColSize)
    {
        if(Row >= 0 && Row < RowSize && Col >= 0 && Col < ColSize)
        {
            return true;
        }
        return false;
    }
};