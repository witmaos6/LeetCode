class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        const int Rows = grid.size();
        const int Cols = grid[0].size();

        int GridSize = Rows * Cols;
        k %= GridSize;

        if(k == 0)
            return grid;

        vector<vector<int>> Result(Rows, vector<int>(Cols));
        for(int Row = 0; Row < Rows; Row++)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                int CurrIndex = Row * Cols + Col;
                int ShiftIndex = (CurrIndex + k) % GridSize;

                int ShiftRow = ShiftIndex / Cols;
                int ShiftCol = ShiftIndex % Cols;

                Result[ShiftRow][ShiftCol] = grid[Row][Col];
            }
        }
        return Result;
    }
};