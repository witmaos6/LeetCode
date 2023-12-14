class Solution {
    int RowSize = 0;
    int ColSize = 0;
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid)
    {
        RowSize = static_cast<int>(grid.size());
        ColSize = static_cast<int>(grid[0].size());
        
        vector<vector<pair<int, int>>> Memo(2);
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
            Memo[0].push_back({Count, ColSize - Count});
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
            Memo[1].push_back({Count, RowSize - Count});
        }
        
        vector<vector<int>> Diff(RowSize, vector<int>(ColSize));
        
        for(int Row = 0; Row < RowSize; Row++)
        {
            for(int Col = 0; Col < ColSize; Col++)
            {
                int RowValue = Memo[0][Row].first - Memo[0][Row].second;
                int ColValue = Memo[1][Col].first - Memo[1][Col].second;
                Diff[Row][Col] = RowValue + ColValue;
            }
        }
        return Diff;
    }
};