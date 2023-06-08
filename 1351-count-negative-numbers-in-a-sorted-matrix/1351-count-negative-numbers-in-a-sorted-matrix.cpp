class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        const size_t RowSize = grid.size();
        const size_t ColSize = grid[0].size();
        
        int Count = 0;
        
        for(size_t Row = 0; Row < RowSize; Row++)
        {
            if(grid[Row].back() < 0)
            {
                int Index = lower_bound(grid[Row].begin(), grid[Row].end(), -1, greater<int>()) - grid[Row].begin();
                
                Count += (ColSize - Index);
            }
        }
        
        return Count;
    }
};