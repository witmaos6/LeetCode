class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices)
    {
        vector<int> RowIncrement(m);
        vector<int> ColIncrement(n);
        
        for(vector<int>& index : indices)
        {
            RowIncrement[index[0]]++;
            ColIncrement[index[1]]++;
        }
        
        vector<vector<int>> Matrix(m, vector<int>(n));
        
        for(int i = 0; i < m; i++)
        {
            if(RowIncrement[i] > 0)
            {
                for(int col = 0; col < n; col++)
                {
                    Matrix[i][col] += RowIncrement[i];
                }
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(ColIncrement[i] > 0)
            {
                for(int row = 0; row < m; row++)
                {
                    Matrix[row][i] += ColIncrement[i];
                }
            }
        }
        
        int Result = 0;
        for(vector<int>& Row : Matrix)
        {
            for(int& Col : Row)
            {
                if(Col & 1)
                {
                    Result++;
                }
            }
        }
        
        return Result;
    }
};