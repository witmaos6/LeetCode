class Solution {
    const int Mod = 1e9 + 7;
    int RowSize = 0;
    int ColSize = 0;
    vector<vector<int>> Memo;
    
    vector<pair<int, int>> Dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int countPaths(vector<vector<int>>& grid)
    {
        RowSize = static_cast<int>(grid.size());
        ColSize = static_cast<int>(grid[0].size());
        
        Memo.resize(RowSize, vector<int>(ColSize, -1));
        
        int Count = 0;
        
        for(int Row = 0; Row < RowSize; Row++)
        {
            for(int Col = 0; Col < ColSize; Col++)
            {
                if(Memo[Row][Col] == -1)
                {
                    Count += DFS(grid, Row, Col);
                    Count %= Mod;
                }
                else
                {
                    Count += Memo[Row][Col];
                    Count %= Mod;
                }
            }
        }
        
        return Count;
    }
    
private:
    int DFS(vector<vector<int>>& Grid, int Row, int Col)
    {
        if(Memo[Row][Col] != -1)
        {
            return Memo[Row][Col];
        }
        
        int DirCount = 0;
        
        for(pair<int, int>& D : Dir)
        {
            int DRow = Row + D.first;
            int DCol = Col + D.second;
            
            if(bInBoundary(DRow, DCol) && Grid[Row][Col] > Grid[DRow][DCol])
            {
                DirCount += DFS(Grid, DRow, DCol);
                DirCount %= Mod;
            }
        }
        
        Memo[Row][Col] = (1 + DirCount) % Mod;
        
        return Memo[Row][Col];
    }
    
    bool bInBoundary(int Row, int Col)
    {
        if(Row >= 0 && Row < RowSize && Col >= 0 && Col < ColSize)
        {
            return true;
        }
        return false;
    }
};