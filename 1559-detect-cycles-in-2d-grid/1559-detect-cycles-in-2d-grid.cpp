class Solution {
    int Rows = 0;
    int Cols = 0;

    vector<vector<bool>> Visited;
public:
    bool containsCycle(vector<vector<char>>& grid)
    {
        Rows = grid.size();
        Cols = grid[0].size();

        Visited.resize(Rows, vector<bool>(Cols, false));

        for(int i = 0; i < Rows; i++)
        {
            for(int j = 0; j < Cols; j++)
            {
                if(!Visited[i][j])
                {
                    if(BFS(i, j, grid))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool BFS(int Row, int Col, vector<vector<char>>& Grid)
    {
        queue<array<int, 4>> Q;
        Q.push({Row, Col, -1, -1});

        array<int, 5> Dir = {-1,0,1,0,-1};

        while(!Q.empty())
        {
            array<int, 4> Curr = Q.front();
            Q.pop();

            int X = Curr[0];
            int Y = Curr[1];
            int PX = Curr[2];
            int PY = Curr[3];

            for(int i = 0; i < 4; i++)
            {
                int DX = X + Dir[i];
                int DY = Y + Dir[i + 1];

                if(DX < 0 || DY < 0 || DX >= Rows || DY >= Cols)
                    continue;
                
                if(Grid[DX][DY] != Grid[X][Y])
                    continue;
                
                if(DX == PX && DY == PY)
                    continue;
                
                if(Visited[DX][DY])
                    return true;
                
                Visited[DX][DY] = true;
                Q.push({DX, DY, X, Y});
            }
        }
        return false;
    }
};