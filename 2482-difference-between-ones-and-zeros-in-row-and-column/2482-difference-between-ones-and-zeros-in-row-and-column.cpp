class Solution {
    int RowSize = 0;
    int ColSize = 0;
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid)
    {
        RowSize = static_cast<int>(grid.size());
        ColSize = static_cast<int>(grid[0].size());
        
        vector<vector<int>> Memo(2);
        for(int Row = 0; Row < RowSize; Row++)
        {
            int Count = 0;
            for(int Col = 0; Col < ColSize; Col++)
            {
                if(grid[Row][Col] == 1)
                {
                    Count++;
                }
            }
            Memo[0].push_back(Count);
        }
        for(int Col = 0; Col < ColSize; Col++)
        {
            int Count = 0;
            for(int Row = 0; Row < RowSize; Row++)
            {
                if(grid[Row][Col] == 1)
                {
                    Count++;
                }
            }
            Memo[1].push_back(Count);
        }
        
        vector<vector<int>> Diff(RowSize, vector<int>(ColSize));
        
        for(int Row = 0; Row < RowSize; Row++)
        {
            for(int Col = 0; Col < ColSize; Col++)
            {
                int Ones = Memo[0][Row] + Memo[1][Col];
                int Zeros = (ColSize - Memo[0][Row]) + (RowSize - Memo[1][Col]);
                Diff[Row][Col] = Ones - Zeros;
            }
        }
        return Diff;
    }
};