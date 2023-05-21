class Solution {
    typedef pair<int, int> Point;
    const int Land = 1;
    const int Water = 0;
    const int Visited = -1;
    int N = 0;
    vector<Point> Dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<Point> Island;
public:
    int shortestBridge(vector<vector<int>>& grid)
    {
        N = static_cast<int>(grid.size());
        
        bool bFindIsland = false;
        
        for(int Row = 0; Row < N; Row++)
        {
            for(int Col = 0; Col < N; Col++)
            {
                if(grid[Row][Col] == Land && !bFindIsland)
                {
                    DFS(grid, Row, Col);
                    Island.push({Row, Col});
                    bFindIsland = true;
                    break;
                }
            }
            if(bFindIsland)
                break;
        }
        
        return BFS(grid);
    }
private:
    void DFS(vector<vector<int>>& Grid, int Row, int Col)
    {
        if(bInBoundary(Row, Col) && Grid[Row][Col] == Land)
        {
            Grid[Row][Col] = Visited;
            
            Island.push({Row, Col});
            
            DFS(Grid, Row + 1, Col);
            DFS(Grid, Row - 1, Col);
            DFS(Grid, Row, Col + 1);
            DFS(Grid, Row, Col - 1);
        }
    }
    
    int BFS(vector<vector<int>>& Grid)
    {
        int Distance = 0;
        int MinDistance = 10001;
        
        while(!Island.empty())
        {
            size_t Range = Island.size();
            
            for(int i = 0; i < Range; i++)
            {
                Point CurrPoint = Island.front();
                Island.pop();
                
                for(Point& D : Dir)
                {
                    int DRow = CurrPoint.first + D.first;
                    int DCol = CurrPoint.second + D.second;
                    
                    if(bInBoundary(DRow, DCol))
                    {
                        if(Grid[DRow][DCol] == Water)
                        {
                            Island.push({DRow, DCol});
                            Grid[DRow][DCol] = Visited;
                        }
                        else if(Grid[DRow][DCol] == Land)
                        {
                            MinDistance = min(MinDistance, Distance);
                        }
                    }
                }
            }
            Distance++;
        }
        
        return MinDistance;
    }
    
    bool bInBoundary(int Row, int Col)
    {
        if(Row >= 0 && Row < N && Col >=0 && Col < N)
        {
            return true;
        }
        return false;
    }
};