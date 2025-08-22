class Solution {
public:
    int minimumArea(vector<vector<int>>& grid)
    {
        const int Rows = static_cast<int>(grid.size());
        const int Cols = static_cast<int>(grid[0].size());
        int minRow = Rows, maxRow = -1;
        int minCol = Cols, maxCol = -1;

        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};