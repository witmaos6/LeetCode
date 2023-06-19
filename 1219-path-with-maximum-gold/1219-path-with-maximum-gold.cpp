class Solution {
    typedef pair<int, int> Point;
    int RowSize = 0;
    int ColSize = 0;
    vector<Point> Dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    int getMaximumGold(vector<vector<int>>& grid)
    {
        RowSize = static_cast<int>(grid.size());
        ColSize = static_cast<int>(grid[0].size());
        
        int MaxGold = 0;
        for(int Row = 0; Row < RowSize; Row++)
        {
            for(int Col = 0; Col < ColSize; Col++)
            {
                if(grid[Row][Col] > 0)
                {
                    int GetGold = DFS(grid, Row, Col, grid[Row][Col]);
                    MaxGold = max(MaxGold, GetGold);
                }
            }
        }
        
        return MaxGold;
    }
    
private:
    int DFS(vector<vector<int>>& Grid, int Row, int Col, int PrefixSum)
    {
        int ValueCache = Grid[Row][Col];
        Grid[Row][Col] = 0;
        
        int MaxPrefix = PrefixSum;
        
        for(Point& D : Dir)
        {
            int DRow = Row + D.first;
            int DCol = Col + D.second;
            
            if(bInBoundary(DRow, DCol) && Grid[DRow][DCol] != 0)
            {
                int Temp = DFS(Grid, DRow, DCol, PrefixSum + Grid[DRow][DCol]);
                
                MaxPrefix = max(MaxPrefix, Temp);
            }
        }
        
        Grid[Row][Col] = ValueCache;
        
        return MaxPrefix;
    }
    
    bool bInBoundary(int Row, int Col)
    {
        if(Row >= 0 && Row < RowSize && Col >=0 && Col < ColSize)
        {
            return true;
        }
        return false;
    }
};