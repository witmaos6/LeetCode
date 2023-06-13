class Solution {
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        const int N = static_cast<int>(grid.size());
        
        map<vector<int>, int> Table;
        
        for(int Row = 0; Row < N; Row++)
        {
            Table[grid[Row]]++;
        }
        
        int Count = 0;
        
        for(int Col = 0; Col < N; Col++)
        {
            vector<int> CurrCol(N);
            for(int Row = 0; Row < N; Row++)
            {
                CurrCol[Row] = grid[Row][Col];
            }
            
            if(Table.find(CurrCol) != Table.end())
            {
                Count += Table[CurrCol];
            }
        }
        
        return Count;
    }
};