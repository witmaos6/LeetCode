class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> Matrix(n, vector<int>(n));
        
        int RowBegin = 0, RowEnd = n - 1;
        int ColBegin = 0, ColEnd = n - 1;
        int Num = 1;
        
        while(RowBegin <= RowEnd && ColBegin <= ColEnd)
        {
            for(int Col = ColBegin; Col <= ColEnd; Col++)
            {
                Matrix[RowBegin][Col] = Num;
                Num++;
            }
            RowBegin++;
            
            for(int Row = RowBegin; Row <= RowEnd; Row++)
            {
                Matrix[Row][ColEnd] = Num;
                Num++;
            }
            ColEnd--;
            
            if(RowBegin > RowEnd || ColBegin > ColEnd)
                break;
            
            for(int Col = ColEnd; Col >= ColBegin; Col--)
            {
                Matrix[RowEnd][Col] = Num;
                Num++;
            }
            RowEnd--;
            
            for(int Row = RowEnd; Row >= RowBegin; Row--)
            {
                Matrix[Row][ColBegin] = Num;
                Num++;
            }
            ColBegin++;
        }
        
        return Matrix;
    }
};