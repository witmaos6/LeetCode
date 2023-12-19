class Solution {
    int RowSize = 0;
    int ColSize = 0;
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img)
    {
        RowSize = static_cast<int>(img.size());
        ColSize = static_cast<int>(img[0].size());
        
        vector<vector<int>> Result(RowSize, vector<int>(ColSize));
        
        for(int Row = 0; Row < RowSize; Row++)
        {
            for(int Col = 0; Col < ColSize; Col++)
            {
                Result[Row][Col] = GetSmoother(img, Row, Col);
            }
        }
        
        return Result;
    }
    
private:
    int GetSmoother(const vector<vector<int>>& Img, int Row, int Col)
    {
        int Sum = 0;
        int Count = 0;
        for(int DirRow = -1; DirRow <= 1; DirRow++)
        {
            for(int DirCol = -1; DirCol <= 1; DirCol++)
            {
                int DRow = Row + DirRow;
                int DCol = Col + DirCol;
                if(InBoundary(DRow, DCol))
                {
                    Sum += Img[DRow][DCol];
                    Count++;
                }
            }
        }
        
        return (Sum / Count);
    }
    
    bool InBoundary(int Row, int Col)
    {
        if(Row >= 0 && Row < RowSize && Col >= 0 && Col < ColSize)
        {
            return true;
        }
        return false;
    }
};