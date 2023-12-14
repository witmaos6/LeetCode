class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid)
    {
        const int RowSize = static_cast<int>(grid.size());
        const int ColSize = static_cast<int>(grid[0].size());
        
        vector<int> RowOnes(RowSize);
        vector<int> ColOnes(ColSize);
        
        for(int Row = 0; Row < RowSize; Row++)
        {
            for(int Col = 0; Col < ColSize; Col++)
            {
                RowOnes[Row] += grid[Row][Col];
                ColOnes[Col] += grid[Row][Col];
            }
        }
        
        for(int Row = 0; Row < RowSize; Row++)
        {
            for(int Col = 0; Col < ColSize; Col++)
            {
                grid[Row][Col] = 2 * (RowOnes[Row] + ColOnes[Col]) - RowSize - ColSize;
            }
        }
        
        return grid;
    }
};