class Solution {
    const int Mod = 1e9 + 7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<int>> Memo(m, vector<int>(n));
        
        Memo[startRow][startColumn] = 1;
        int Count = 0;
        
        for(int Move = 1; Move <= maxMove; Move++)
        {
            vector<vector<int>> Temp(m, vector<int>(n));
            
            for(int Row = 0; Row < m; Row++)
            {
                for(int Col = 0; Col < n; Col++)
                {
                    if(Row == 0)
                    {
                        Count = (Count + Memo[Row][Col]) % Mod;
                    }
                    if(Col == 0)
                    {
                        Count = (Count + Memo[Row][Col]) % Mod;
                    }
                    if(Row == m - 1)
                    {
                        Count = (Count + Memo[Row][Col]) % Mod;
                    }
                    if(Col == n - 1)
                    {
                        Count = (Count + Memo[Row][Col]) % Mod;
                    }
                    
                    Temp[Row][Col] = GetCellNum(Memo, Row, Col, m, n);
                }
            }
            Memo = Temp;
        }
        
        return Count;
    }
private:    
    int GetCellNum(const vector<vector<int>>& Memo, int Row, int Col, int RowSize, int ColSize)
    {
        int Num1 = 0;
        Num1 = ((Row > 0 ? Memo[Row - 1][Col] : 0) + (Row < RowSize - 1 ? Memo[Row + 1][Col] : 0)) % Mod;
        
        int Num2 = 0;
        Num2 = ((Col > 0 ? Memo[Row][Col - 1] : 0) + (Col < ColSize - 1 ? Memo[Row][Col + 1] : 0)) % Mod;
        
        return (Num1 + Num2) % Mod;
    }
};