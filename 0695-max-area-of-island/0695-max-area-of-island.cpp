class Solution {
    typedef pair<int, int> Point;
    const int Land = 1;
    const int Water = 0;
    int RowSize = 0;
    int ColSize = 0;
    vector<Point> Div = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        RowSize = static_cast<int>(grid.size());
        ColSize = static_cast<int>(grid[0].size());
        int MaxIsland = 0;
        
        for(int Row = 0; Row < RowSize; Row++)
        {
            for(int Col = 0; Col < ColSize; Col++)
            {
                if(grid[Row][Col] == Land)
                {
                    MaxIsland = max(MaxIsland, BFS(grid, Row, Col));
                }
            }
        }
        
        return MaxIsland;
    }
    
private:
    int BFS(vector<vector<int>>& grid, int Row, int Col)
    {
        int LandSize = 0;
        queue<Point> q;
        q.push({Row, Col});
        grid[Row][Col] = Water;
        
        while(!q.empty())
        {
            size_t Range = q.size();
            LandSize += static_cast<int>(Range);
            
            for(size_t i = 0; i < Range; i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(Point& D : Div)
                {
                    int NextRow = row + D.first;
                    int NextCol = col + D.second;
                    
                    if(bInBoundary(NextRow, NextCol) && grid[NextRow][NextCol] == Land)
                    {
                        grid[NextRow][NextCol] = Water;
                        q.push({NextRow, NextCol});
                    }
                }
            }
        }
        
        return LandSize;
    }
    
    bool bInBoundary(int Row, int Col)
    {
        if(Row >= 0 && Row < RowSize && Col >= 0 && Col < ColSize)
        {
            return true;
        }
        return false;
    }
};