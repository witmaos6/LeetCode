class Solution {
    int Rows = 0;
    int Cols = 0;
    int TotalPerimeter = 0;
    array<pair<int, int>, 4> Dir = {{{0,1}, {0,-1}, {1,0}, {-1,0}}};
    vector<vector<bool>> Visited;
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        Rows = static_cast<int>(grid.size());
        Cols = static_cast<int>(grid[0].size());
        Visited.resize(Rows, vector<bool>(Cols, false));
        
        for(int Row = 0; Row < Rows; Row++)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                if(grid[Row][Col] == 1)
                {
                    BFS(grid, Row, Col);
                    break;
                }
            }
        }
        return TotalPerimeter;
    }
    
private:
    void BFS(const vector<vector<int>>& Grid, const int Row, const int Col)
    {
        if(Visited[Row][Col])
            return;
        
        Visited[Row][Col] = true;
        int Perimeter = 4;
        
        for(pair<int, int>& D : Dir)
        {
            int DRow = Row + D.first;
            int DCol = Col + D.second;
            
            if(IsIsland(Grid, DRow, DCol))
            {
                if(!Visited[DRow][DCol])
                {
                    BFS(Grid, DRow, DCol);
                }
                Perimeter--;
            }
        }
        TotalPerimeter += Perimeter;
    }
    
    bool IsIsland(const vector<vector<int>>& Grid, const int Row, const int Col)
    {
        if(Row >= 0 && Col >= 0 && Row < Rows && Col < Cols && Grid[Row][Col] == 1)
        {
            return true;
        }
        return false;
    }
};