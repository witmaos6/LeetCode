class Solution {
    typedef pair<int, int> Point;
    int RowSize = 0;
    int ColSize = 0;
    const int Mod = 1e9 + 7;
    vector<vector<vector<int>>> Table;
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
                for(int i = 0; i < k; i++)
                {
                    if(Table[Row - 1][Col][i] == 0)
                    {
                        continue;
                    }
                    int Temp = (grid[Row][Col] + i) % k;
                    Table[Row][Col][Temp] += Table[Row - 1][Col][i];
                    Table[Row][Col][Temp] %= Mod;
                }
                
                for(int i = 0; i < k; i++)
                {
                    if(Table[Row][Col - 1][i] == 0)
                    {
                        continue;
                    }
                    int Temp = (grid[Row][Col] + i) % k;
                    Table[Row][Col][Temp] += Table[Row][Col - 1][i];
                    Table[Row][Col][Temp] %= Mod;
                }
            }
        }
        
        return Table[RowSize - 1][ColSize - 1][0] % Mod;
    }
    
private:
    void InitTable(const vector<vector<int>>& Grid, int K)
    {
        vector<vector<int>> Temp(ColSize, vector<int>(K));
        Table.resize(RowSize, Temp);
        
        int Begin = Grid[0][0] % K;
        Table[0][0][Begin] = 1;
        
        int ColValue = Begin;
        for(int Col = 1; Col < ColSize; Col++)
        {
            int CurrValue = (ColValue + Grid[0][Col]) % K;
            Table[0][Col][CurrValue] = 1;
            ColValue = CurrValue;
        }
        
        int RowValue = Begin;
        for(int Row = 1; Row < RowSize; Row++)
        {
            int CurrValue = (RowValue + Grid[Row][0]) % K;           
            Table[Row][0][CurrValue] = 1;
            RowValue = CurrValue;
        }
    } 
};