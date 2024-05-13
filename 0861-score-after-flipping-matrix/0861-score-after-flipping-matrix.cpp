class Solution {
public:
    int matrixScore(vector<vector<int>>& grid)
    {
        const int Rows = static_cast<int>(grid.size());
        const int Cols = static_cast<int>(grid[0].size());
        
        for(int Row = 0; Row < Rows; Row++)
        {
            if(grid[Row].front() == 0)
            {
                FlipRow(grid[Row], Cols);
            }
        }
        
        for(int Col = 1; Col < Cols; Col++)
        {
            int NrOfZeros = 0;
            for(int Row = 0; Row < Rows; Row++)
            {
                if(grid[Row][Col] == 0)
                {
                    NrOfZeros++;
                }
            }
            
            if(NrOfZeros > Rows / 2)
            {
                for(int Row = 0; Row < Rows; Row++)
                {
                    grid[Row][Col] = (grid[Row][Col] == 0) ? 1 : 0;
                }
            }
        }
        
        int Result = 0;
        for(int Row = 0; Row < Rows; Row++)
        {
            int Value = 0;
            int Binary = 1;
            for(int Col = Cols - 1; Col >= 0; Col--)
            {
                Value += grid[Row][Col] * Binary;
                Binary <<= 1;
            }
            Result += Value;
        }
        
        return Result;
    }
    
private:
    void FlipRow(vector<int>& Row, const int N)
    {
        for(int i = 0; i < N; i++)
        {
            Row[i] = (Row[i] == 0) ? 1 : 0;
        }
    }
};