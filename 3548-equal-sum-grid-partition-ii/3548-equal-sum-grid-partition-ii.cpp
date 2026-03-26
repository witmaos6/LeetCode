class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid)
    {
        const int Rows = grid.size();
        const int Cols = grid[0].size();

        long long Total = 0;
        unordered_map<long long, int> Bottom, Top, Left, Right;
        for(vector<int>& Row : grid)
        {
            for(int& Num : Row)
            {
                Total += Num;
                Bottom[Num]++;
                Right[Num]++;
            }
        }

        long long SumTop = 0;
        for(int i = 0; i < Rows - 1; i++)
        {
            for(int j = 0; j < Cols; j++)
            {
                int Val = grid[i][j];
                SumTop += Val;

                Top[Val]++;
                Bottom[Val]--;
            }

            long long SumBottom = Total - SumTop;
            if(SumTop == SumBottom)
                return true;
            
            long long Diff = abs(SumTop - SumBottom);
            if(SumTop > SumBottom)
            {
                if(Check(Top, grid, 0, i, 0, Cols - 1, Diff))
                    return true;
            }
            else
            {
                if(Check(Bottom, grid, i + 1, Rows - 1, 0, Cols - 1, Diff))
                    return true;
            }
        }

        long long SumLeft = 0;
        for(int j = 0; j < Cols - 1; j++)
        {
            for(int i = 0; i < Rows; i++)
            {
                int Val = grid[i][j];
                SumLeft += Val;
                Left[Val]++;
                Right[Val]--;
            }

            long long SumRight = Total - SumLeft;
            if(SumLeft == SumRight)
                return true;
            
            long long Diff = abs(SumLeft - SumRight);
            if(SumLeft > SumRight)
            {
                if(Check(Left, grid, 0, Rows - 1, 0, j, Diff))
                    return true;
            }
            else
            {
                if(Check(Right, grid, 0, Rows - 1, j + 1, Cols - 1, Diff))
                    return true;
            }
        }
        return false;
    }
private:
    bool Check(unordered_map<long long, int>& Table, vector<vector<int>>& Grid,
        int R1, int R2, int C1, int C2, long long Diff)
    {
        int Rows = R2 - R1 + 1;
        int Cols = C2 - C1 + 1;
        if(Rows * Cols == 1)
            return false;

        if(Rows == 1)
            return (Grid[R1][C1] == Diff || Grid[R1][C2] == Diff);

        if(Cols == 1)
            return (Grid[R1][C1] == Diff || Grid[R2][C1] == Diff);
        
        return Table[Diff] > 0;
    }
};