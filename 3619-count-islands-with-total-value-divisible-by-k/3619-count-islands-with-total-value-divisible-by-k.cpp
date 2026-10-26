class Solution {
    int Rows = 0;
    int Cols = 0;
    using Point = pair<int, int>;
    array<int, 5> Dir = {1, 0, -1, 0, 1};
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

                int Sum = BFS(grid, Row, Col);
                if(Sum % k == 0)
                    Count++;
            }
        }
        return Count;
    }

private:
    int BFS(vector<vector<int>>& Grid, int BeginRow, int BeginCol)
    {
        queue<Point> Q;
        Q.push({BeginRow, BeginCol});
        int Sum = 0;

        while(!Q.empty())
        {
            auto[Row, Col] = Q.front();
            Q.pop();

            if(Grid[Row][Col] == 0)
                continue;

            Sum = (Sum + Grid[Row][Col]) % K;
            Grid[Row][Col] = 0;

            for(int i = 0; i < 4; i++)
            {
                int DRow = Row + Dir[i];
                int DCol = Col + Dir[i + 1];

                if(InBoundary(DRow, DCol) && Grid[DRow][DCol] > 0)
                {
                    Q.push({DRow, DCol});
                }
            }
        }
        return Sum;
    }

    bool InBoundary(int Row, int Col)
    {
        return (Row >= 0 && Row < Rows && Col >= 0 && Col < Cols);
    }
};