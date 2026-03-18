class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k)
    {
        const int Rows = static_cast<int>(grid.size());
        const int Cols = static_cast<int>(grid[0].size());

        int Result = 0;

        for(int Row = 0; Row < Rows; Row++)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                int PrefixSum = grid[Row][Col];

                if(Row > 0)
                {
                    PrefixSum += grid[Row - 1][Col];
                }
                if(Col > 0)
                {
                    PrefixSum += grid[Row][Col - 1];
                }
                if(Row > 0 && Col > 0)
                {
                    PrefixSum -= grid[Row - 1][Col - 1];
                }
                grid[Row][Col] = PrefixSum;

                if(grid[Row][Col] <= k)
                {
                    Result++;
                }
            }
        }
        return Result;
    }
};