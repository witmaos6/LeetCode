class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid)
    {
        const int RowSize = static_cast<int>(grid.size());
        const int ColSize = static_cast<int>(grid[0].size());
        
        for(int Row = 0; Row < RowSize; Row++)
        {
            sort(grid[Row].begin(), grid[Row].end());
        }
        
        int Answer = 0;
        
        for(int Col = ColSize - 1; Col >= 0; Col--)
        {
            int MaxValue = 0;
            
            for(int Row = 0; Row < RowSize; Row++)
            {
                MaxValue = max(MaxValue, grid[Row][Col]);
            }
            
            Answer += MaxValue;
        }
        
        return Answer;
    }
};