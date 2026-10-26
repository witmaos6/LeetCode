class Solution {
    int Rows = 0;
    int Cols = 0;
    using Point = pair<int, int>;
    int K = 0;
public:
    int countIslands(vector<vector<int>>& grid, int k)
    {
        Rows = grid.size();
        Cols = grid[0].size();
        K = k;

        int Count = 0;
        for(int Row = 0; Row < Rows; Row++)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                if(grid[Row][Col] == 0)
                    continue;

                int Sum = DFS(grid, Row, Col);
                if(Sum % k == 0)
                    Count++;
            }
        }
        return Count;
    }
private:
array<int, 5> Dir = {1, 0, -1, 0, 1};

    int DFS(vector<vector<int>>& Grid, int Row, int Col)
    {
        int Sum = Grid[Row][Col];
        Grid[Row][Col] = 0;

        for(int i = 0; i < 4; i++)
        {
            int DRow = Row + Dir[i];
            int DCol = Col + Dir[i + 1];

            if(InBoundary(DRow, DCol) && Grid[DRow][DCol] > 0)
            {
                Sum = (Sum + DFS(Grid, DRow, DCol)) % K;
            }
        }
        return Sum;
    }

    bool InBoundary(int Row, int Col)
    {
        return (Row >= 0 && Row < Rows && Col >= 0 && Col < Cols);
    }
};