class Solution {
    const int Sea = 0;
    const int Land = 1;
    const int Visited = 2;
    int RowSize = 0;
    int ColSize = 0;
public:
    int numEnclaves(vector<vector<int>>& grid)
    {
        RowSize = static_cast<int>(grid.size());
        ColSize = static_cast<int>(grid[0].size());

        int Result = 0;

        for(int row = 0; row < RowSize; row++)
        {
            for(int col = 0; col < ColSize; col++)
            {
                if(grid[row][col] == Land)
                {
                    bool WalkOffBoundary = false;
                    int NrOfLand = 0;
                    DFS(grid, row, col, NrOfLand, WalkOffBoundary);
                    
                    if(!WalkOffBoundary)
                    {
                        Result += NrOfLand;
                    }
                }
            }
        }

        return Result;
    }
private:
    void DFS(vector<vector<int>>& grid, int row, int col, int& NrOfLand, bool& State)
    {
        if(bIsValidBoundary(row, col) && grid[row][col] == Land)
        {
            if(bWalkOffBoundary(row, col))
            {
                State = true;
            }
            NrOfLand++;
            grid[row][col] = Visited;

            DFS(grid, row + 1, col, NrOfLand, State);
            DFS(grid, row - 1, col, NrOfLand, State);
            DFS(grid, row, col + 1, NrOfLand, State);
            DFS(grid, row, col - 1, NrOfLand, State);
        }
    }

    bool bIsValidBoundary(int row, int col)
    {
        if(row >= 0 && row < RowSize && col >= 0 && col < ColSize)
        {
            return true;
        }
        return false;
    }

    bool bWalkOffBoundary(int row, int col)
    {
        if(row == 0 || row == RowSize - 1 || col == 0 || col == ColSize - 1)
        {
            return true;
        }
        return false;
    }
};