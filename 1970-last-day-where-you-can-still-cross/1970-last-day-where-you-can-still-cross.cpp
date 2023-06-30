class Solution {
    const int Land = 0;
    const int Water = 1;
    typedef pair<int, int> Point;
    
    vector<int> Dir = {1,0,-1,0,1};
    int RowSize;
    int ColSize;
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells)
    {
        RowSize = row;
        ColSize = col;
        int Left = 0, Right = row * col;
        
        while(Left < Right - 1)
        {
            int Mid = (Left + Right) / 2;
            
            if(bIsPossible(cells, Mid))
            {
                Left = Mid;
            }
            else
            {
                Right = Mid;
            }
        }
        
        return Left;
    }
    
private:
    bool bIsPossible(const vector<vector<int>>& Cells, const int Day)
    {
        vector<vector<int>> Grid(RowSize + 1, vector<int>(ColSize + 1));
        for(int i = 0; i < Day; i++)
        {
            Grid[Cells[i][0]][Cells[i][1]] = Water;
        }
        
        queue<Point> BFS;
        for(int i = 1; i <= ColSize; i++)
        {
            if(Grid[1][i] == Land)
            {
                BFS.push({1, i});
            }
            Grid[1][i] = Water;
        }
        
        while(!BFS.empty())
        {
            Point P = BFS.front();
            BFS.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int DRow = P.first + Dir[i];
                int DCol = P.second + Dir[i + 1];
                
                if(bInBoundary(DRow, DCol) && Grid[DRow][DCol] == 0)
                {
                    Grid[DRow][DCol] = Water;
                    
                    if(DRow == RowSize)
                    {
                        return true;
                    }
                    BFS.push({DRow, DCol});
                }
            }
        }
        
        return false;
    }
    
    bool bInBoundary(int Row, int Col)
    {
        if(Row > 0 && Row <= RowSize && Col > 0 && Col <= ColSize)
        {
            return true;
        }
        return false;
    }
};