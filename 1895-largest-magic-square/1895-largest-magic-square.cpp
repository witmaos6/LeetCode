class Solution {
    int Rows = 0;
    int Cols = 0;
public:
    int largestMagicSquare(vector<vector<int>>& grid)
    {
        Rows = static_cast<int>(grid.size());
        Cols = static_cast<int>(grid[0].size());

        int MaxRange = min(Rows, Cols);
        int Result = 1;
        for(int i = 2; i <= MaxRange; i++)
        {
            for(int Row = 0; Row + i <= Rows; Row++)
            {
                for(int Col = 0; Col + i <= Cols; Col++)
                {
                    if(IsMagicSquare(Row, Col, i, grid))
                    {
                        Result = i;
                    }
                }
            }
        }

        return Result;
    }
private:
    bool IsMagicSquare(int Row, int Col, int L, const vector<vector<int>>& Grid)
    {
        int Sum = 0;
        for(int C = Col; C < Col + L; C++)
        {
            Sum += Grid[Row][C];
        }

        for(int R = Row + 1; R < Row + L; R++)
        {
            int CurrSum = 0;
            for(int C = Col; C < Col + L; C++)
            {
                CurrSum += Grid[R][C];
            }
            if(Sum != CurrSum)
                return false;
        }

        for(int C = Col; C < Col + L; C++)
        {
            int CurrSum = 0;
            for(int R = Row; R < Row + L; R++)
            {
                CurrSum += Grid[R][C];
            }
            if(Sum != CurrSum)
                return false;
        }

        int DiaSum = 0;
        for(int i = 0; i < L; i++)
        {
            DiaSum += Grid[Row + i][Col + i];
        }
        if(DiaSum != Sum)
            return false;

        int RDiaSum = 0;
        for(int i = 0; i < L; i++)
        {
            RDiaSum += Grid[Row + i][Col + L - 1 - i];
        }
        if(RDiaSum != Sum)
            return false;

        return true;
    }
};