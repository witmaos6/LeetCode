class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k)
    {
        const int Rows = static_cast<int>(grid.size());
        const int Cols = static_cast<int>(grid[0].size());

        int Result = (grid[0][0] <= k) ? 1 : 0;
        for(int i = 1; i < Cols; i++)
        {
            grid[0][i] += grid[0][i - 1];

            if(grid[0][i] <= k)
            {
                Result++;
            }
        }

        for(int Row = 1; Row < Rows; Row++)
        {
            grid[Row][0] += grid[Row - 1][0];
            if(grid[Row][0] <= k)
            {
                Result++;
            }

            for(int Col = 1; Col < Cols; Col++)
            {
                grid[Row][Col] = (grid[Row][Col] + grid[Row - 1][Col] + grid[Row][Col - 1] - grid[Row - 1][Col - 1]);
                if(grid[Row][Col] <= k)
                {
                    Result++;
                }
            }
        }
        return Result;
    }
};