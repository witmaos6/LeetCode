class Solution {
    using Pair = pair<int, int>;
    int Rows = 0;
    int Cols = 0;
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health)
    {
        Rows = grid.size();
        Cols = grid[0].size();

        deque<Pair> Dq;
        vector<vector<int>> Dist(Rows, vector<int>(Cols, INT_MAX));
        Dist[0][0] = grid[0][0];
        Dq.push_front({0, 0});

        array<int, 5> Dir = {-1, 0, 1, 0, -1};

        while(!Dq.empty())
        {
            auto[X, Y] = Dq.front();
            Dq.pop_front();

            for(int i = 0; i < 4; i++)
            {
                int DX = X + Dir[i];
                int DY = Y + Dir[i + 1];

                if(!InBoundary(DX, DY))
                    continue;

                int W = grid[DX][DY];
                if(Dist[X][Y] + W < Dist[DX][DY])
                {
                    Dist[DX][DY] = Dist[X][Y] + W;
                    if(W == 0)
                    {
                        Dq.push_front({DX, DY});
                    }
                    else
                    {
                        Dq.push_back({DX, DY});
                    }
                }
            }
        }
        return Dist[Rows - 1][Cols - 1] < health;
    }

    bool InBoundary(int Row, int Col)
    {
        if(Row >= 0 && Row < Rows && Col >= 0 && Col < Cols)
            return true;
        
        return false;
    }
};