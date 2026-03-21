class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k)
    {
        int SwapRow = x + k - 1;
        int Range = x + (k / 2);
        for(int i = x; i < Range; i++)
        {
            for(int j = y; j < y + k; j++)
            {
                swap(grid[i][j], grid[SwapRow][j]);
            }
            SwapRow--;
        }
        return grid;
    }
};