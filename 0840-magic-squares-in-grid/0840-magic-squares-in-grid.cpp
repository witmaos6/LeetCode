class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        const int Rows = static_cast<int>(grid.size());
        const int Cols = static_cast<int>(grid[0].size());
        
        if(Rows < 3 || Cols < 3)
        {
            return 0;
        }
        
        int Count = 0;
        for(int Row = 0; Row < Rows - 2; Row++)
        {
            for(int Col = 0; Col < Cols - 2; Col++)
            {
                if(IsMagicSquareCondition(grid, Row, Col) && IsMagicSquare(grid, Row, Col))
                {
                    Count++;
                }
            }
        }
        
        return Count;
    }
private:
    bool IsMagicSquareCondition(const vector<vector<int>>& Grid, const int Row, const int Col)
    {
        vector<int> Table(10);
        for(int i = Row; i < Row + 3; i++)
        {
            for(int j = Col; j < Col + 3; j++)
            {
                if(Grid[i][j] >= 0 && Grid[i][j] <= 9)
                {
                    Table[Grid[i][j]] = 1;
                }
                else
                {
                    return false;
                }
            }
        }
        for(int i = 1; i < 10; i++)
        {
            if(Table[i] == 0)
                return false;
        }
        return true;
    }
    
    bool IsMagicSquare(const vector<vector<int>>& Grid, const int Row, const int Col)
    {
        int Sum = Grid[Row][Col] + Grid[Row][Col + 1] + Grid[Row][Col + 2];
        
        for(int i = Row; i < Row + 3; i++)
        {
            int CurrSum = 0;
            for(int j = Col; j < Col + 3; j++)
            {
                CurrSum += Grid[i][j];
            }
            if(CurrSum != Sum)
                return false;
        }
        
        for(int i = Col; i < Col + 3; i++)
        {
            int CurrSum = 0;
            for(int j = Row; j < Row + 3; j++)
            {
                CurrSum += Grid[j][i];
            }
            if(CurrSum != Sum)
                return false;
        }
        
        int DiagonalSum = Grid[Row][Col] + Grid[Row + 1][Col + 1] + Grid[Row + 2][Col + 2];
        if(DiagonalSum != Sum)
            return false;
        
        int ReverseDiagonal = Grid[Row + 2][Col] + Grid[Row + 1][Col + 1] + Grid[Row][Col + 2];
        if(ReverseDiagonal != Sum)
            return false;
        
        return true;
    }
};