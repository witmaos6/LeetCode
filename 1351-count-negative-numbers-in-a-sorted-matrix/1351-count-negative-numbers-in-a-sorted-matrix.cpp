class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        const size_t RowSize = grid.size();
        const size_t ColSize = grid[0].size();
        
        int Count = 0;
        
        for(size_t Row = 0; Row < RowSize; Row++)
        {
            for(size_t Col = 0; Col < ColSize; Col++)
            {
                if(grid[Row][Col] < 0)
                {
                    int Temp = ColSize - Col;
                    Count += Temp;
                    break;
                }
            }
        }
        
        return Count;
    }
};