class Solution {
    const int Communicate = 2;
public:
    int countServers(vector<vector<int>>& grid)
    {
        const int Rows = static_cast<int>(grid.size());
        const int Cols = static_cast<int>(grid[0].size());

        vector<int> NrOfRowIndex(Rows);
        vector<int> NrOfColIndex(Cols);

        for(int Row = 0; Row < Rows; Row++)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                NrOfRowIndex[Row] += grid[Row][Col];
                NrOfColIndex[Col] += grid[Row][Col];
            }
        }

        int CountServer = 0;
        for(int Row = 0; Row < Rows; Row++)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                if(grid[Row][Col] == 1 && (NrOfRowIndex[Row] > 1 || NrOfColIndex[Col] > 1))
                {
                    CountServer++;
                }
            }
        }

        return CountServer;
    }
};