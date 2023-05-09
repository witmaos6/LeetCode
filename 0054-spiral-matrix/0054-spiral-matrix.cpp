class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& Matrix)
    {
        const int RowSize = static_cast<int>(Matrix.size());
        const int ColSize = static_cast<int>(Matrix[0].size());
        
        int RowBegin = 0, RowEnd = RowSize - 1;
        int ColBegin = 0, ColEnd = ColSize - 1;
        vector<int> Result;
        Result.reserve(RowSize * ColSize);
        
        while(RowBegin <= RowEnd && ColBegin <= ColEnd)
        {
            for(int Col = ColBegin; Col <= ColEnd; Col++)
            {
                Result.push_back(Matrix[RowBegin][Col]);
            }
            RowBegin++;
            
            for(int Row = RowBegin; Row <= RowEnd; Row++)
            {
                Result.push_back(Matrix[Row][ColEnd]);
            }
            ColEnd--;
            
            if(RowBegin > RowEnd || ColBegin > ColEnd)
                break;
            
            for(int Col = ColEnd; Col >= ColBegin; Col--)
            {
                Result.push_back(Matrix[RowEnd][Col]);
            }
            RowEnd--;
            
            for(int Row = RowEnd; Row >= RowBegin; Row--)
            {
                Result.push_back(Matrix[Row][ColBegin]);
            }
            ColBegin++;
        }
        
        return Result;
    }
};