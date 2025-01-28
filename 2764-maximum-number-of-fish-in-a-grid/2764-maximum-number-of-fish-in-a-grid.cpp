class Solution {
    int Rows = 0;
    int Cols = 0;
public:
    int findMaxFish(vector<vector<int>>& grid)
    {
        Rows = static_cast<int>(grid.size());
        Cols = static_cast<int>(grid[0].size());

        int MaxFishes = 0;
        for(int Row = 0; Row < Rows; Row++)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                if(grid[Row][Col] > 0)
                {
                    int Fishes = DFS(grid, Row, Col);
                    MaxFishes = max(MaxFishes, Fishes);
                }
            }
        }

        return MaxFishes;
    }
private:
    array<int, 5> Dir = {-1,0,1,0,-1};
    using Point = pair<int, int>;
    int DFS(vector<vector<int>>& grid, const int Row, const int Col)
    {
        if(!InBoundary(Row, Col) || grid[Row][Col] == 0)
            return 0;

        int Fishes = grid[Row][Col];
        grid[Row][Col] = 0;

        for(int i = 0; i < 4; i++)
        {
            int DRow = Row + Dir[i];
            int DCol = Col + Dir[i + 1];
            Fishes += DFS(grid, DRow, DCol);
        }
        return Fishes;
    }

    bool InBoundary(const int Row, const int Col)
    {
        if(Row >= 0 && Row < Rows && Col >= 0 && Col < Cols)
            return true;
        
        return false;
    }
};