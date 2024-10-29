class Solution {
    int Rows = 0;
    int Cols = 0;
    array<int, 3> Dir = {-1, 0, 1};
    vector<vector<int>> Memo;
public:
    int maxMoves(vector<vector<int>>& grid)
    {
        Rows = static_cast<int>(grid.size());
        Cols = static_cast<int>(grid[0].size());
        
        Memo.resize(Rows, vector<int>(Cols, -1));
        
        int MaxMove = 0;
        for(int i = 0; i < Rows; ++i)
        {
            int Move = DFS(grid, i, 0, grid[i][0]);
            MaxMove = max(MaxMove, Move);
        }
        
        return MaxMove;
    }
    
private:
    int DFS(const vector<vector<int>>& Grid, int Row, int Col, int PreValue)
    {
        if(Col >= Cols)
        {
            return 0;
        }
        if(Memo[Row][Col] != -1)
        {
            return Memo[Row][Col];
        }
        
        int Move = 0;
        const int DCol = Col + 1;
        for(int D : Dir)
        {
            const int DRow = Row + D;
            if(InBoundary(DRow, DCol) && Grid[DRow][DCol] > PreValue)
            {
                int Temp = DFS(Grid, DRow, DCol, Grid[DRow][DCol]) + 1;
                Move = max(Move, Temp);
            }
        }
        
        Memo[Row][Col] = max(Memo[Row][Col], Move);
        return Memo[Row][Col];
    }
    
    bool InBoundary(const int Row, const int Col)
    {
        if(Row >= 0 && Row < Rows && Col >= 0 && Col < Cols)
            return true;
        
        return false;
    }
};