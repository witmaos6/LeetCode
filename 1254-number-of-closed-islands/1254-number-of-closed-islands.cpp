class Solution {
    using Point = pair<int, int>;
    const int Land = 0;
    const int Water = 1;
    const int Visited = 2;

    int RowSize = 0;
    int ColSize = 0;
    vector<Point> Next = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int closedIsland(vector<vector<int>>& grid)
    {
        RowSize = static_cast<int>(grid.size());
        ColSize = static_cast<int>(grid[0].size());

        int Result = 0;
        for(int row = 1; row < RowSize - 1; row++)
        {
            for(int col = 1; col < ColSize - 1; col++)
            {
                if(grid[row][col] == 0)
                {
                    if(bIsIsland(grid, {row, col}))
                    {
                        Result++;
                    }
                }
            }
        }

        return Result;
    }

private:
    bool bIsIsland(vector<vector<int>>& grid, Point P)
    {
        queue<Point> q;
        q.push(P);
        bool bIsIsland = true;

        while(!q.empty())
        {
            Point Curr = q.front();
            q.pop();
            grid[Curr.first][Curr.second] = Visited;

            for(Point next : Next)
            {
                int Row = Curr.first + next.first;
                int Col = Curr.second + next.second;
                if(!bValidBoundary({Row, Col}) || grid[Row][Col] == Visited)
                {
                    continue;
                }

                if(grid[Row][Col] == 0)
                {
                    if(!bIslandBoundary({Row, Col}))
                    {
                        bIsIsland = false;
                    }
                    q.push({Row, Col});
                }
            }
        }
        return bIsIsland;
    }

    bool bIslandBoundary(Point P)
    {
        if(P.first > 0 && P.first < RowSize - 1 && P.second > 0 && P.second < ColSize - 1)
        {
            return true;
        }
        return false;
    }

    bool bValidBoundary(Point P)
    {
        if(P.first >= 0 && P.first < RowSize && P.second >= 0 && P.second < ColSize)
        {
            return true;
        }
        return false;
    }
};