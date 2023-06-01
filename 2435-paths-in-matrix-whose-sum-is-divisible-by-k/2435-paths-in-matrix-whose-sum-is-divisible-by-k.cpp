class Solution {
    typedef pair<int, int> Point;
    int RowSize = 0;
    int ColSize = 0;
    const int Mod = 1e9 + 7;
    vector<vector<map<int, int>>> Table;
public:
    int numberOfPaths(vector<vector<int>>& grid, int k)
    {
        RowSize = static_cast<int>(grid.size());
        ColSize = static_cast<int>(grid[0].size());
        
        InitTable(grid, k);
        
        for(int Row = 1; Row < RowSize; Row++)
        {
            for(int Col = 1; Col < ColSize; Col++)
            {
                map<int, int>& PrevRowMap = Table[Row -1][Col];
                
                for(pair<const int, int>& E : PrevRowMap)
                {
                    int Temp = (grid[Row][Col] + E.first) % k;
                    
                    Table[Row][Col][Temp] += E.second % Mod;
                }
                
                map<int, int>& PrevColMap = Table[Row][Col -1];
                for(pair<const int, int>& E : PrevColMap)
                {
                    int Temp = (grid[Row][Col] + E.first) % k;
                    
                    Table[Row][Col][Temp] += E.second % Mod;
                }
            }
        }
        
        return Table[RowSize - 1][ColSize - 1][0] % Mod;
    }
    
private:
    void InitTable(const vector<vector<int>>& Grid, int K)
    {
        Table.resize(RowSize, vector<map<int, int>>(ColSize));
        
        Table[0][0][Grid[0][0] % K] = 1;
        
        int ColValue = Grid[0][0] % K;
        for(int Col = 1; Col < ColSize; Col++)
        {
            map<int, int>& Map = Table[0][Col];
            int CurrValue = (ColValue + Grid[0][Col]) % K;
            
            Map[CurrValue] = 1;
            ColValue = CurrValue;
        }
        
        int RowValue = Grid[0][0] % K;
        for(int Row = 1; Row < RowSize; Row++)
        {
            map<int, int>& Map = Table[Row][0];
            int CurrValue = (RowValue + Grid[Row][0]) % K;
            
            Map[CurrValue] = 1;
            RowValue = CurrValue;
        }
    } 
};