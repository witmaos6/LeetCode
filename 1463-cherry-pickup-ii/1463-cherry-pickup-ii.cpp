class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid)
    {
        const int RowSize = static_cast<int>(grid.size());
        const int ColSize = static_cast<int>(grid[0].size());
        
        vector<vector<vector<int>>> Memo(2, vector<vector<int>>(ColSize, vector<int>(ColSize)));
        
        for(int Col1 = 0; Col1 < ColSize; Col1++)
        {
            int Row = RowSize - 1;
            for(int Col2 = 0; Col2 < ColSize; Col2++)
            {
                int Value = (Col1 != Col2) ? grid[Row][Col1] + grid[Row][Col2] : grid[Row][Col1];
                Memo[Row & 1][Col1][Col2] = Value;
            }
        }
        
        for(int Row = RowSize - 2; Row >= 0; Row--)
        {
            for(int Col1 = 0; Col1 < ColSize; Col1++)
            {
                for(int Col2 = 0; Col2 < ColSize; Col2++)
                {
                    int Cherry = (Col1 != Col2) ? grid[Row][Col1] + grid[Row][Col2] : grid[Row][Col1];
                    int Next = 0;
                    
                    for(int Dir1 : {Col1 - 1, Col1, Col1 + 1})
                    {
                        for(int Dir2 : {Col2 - 1, Col2, Col2 + 1})
                        {
                            if(Dir1 < 0 || Dir1 >= ColSize || Dir2 < 0 || Dir2 >= ColSize)
                            {
                                continue;
                            }
                            Next = max(Next, Memo[(Row + 1) & 1][Dir1][Dir2]);
                        }
                    }
                    Memo[Row & 1][Col1][Col2] = Next + Cherry;
                }
            }
        }
        
        return Memo[0][0].back();
    }
};