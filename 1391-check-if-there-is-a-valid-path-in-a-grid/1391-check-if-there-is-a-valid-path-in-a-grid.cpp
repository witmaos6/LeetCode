class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid)
    {
        if(grid[0][0] == 5 || grid.back().back() == 4)
            return false;

        int Rows = grid.size();
        int Cols = grid[0].size();

        if(Rows == 1 && Cols == 1)
            return true;

        vector<vector<pair<int, int>>> Dir(7);
        Dir[1] = {{0,-1},{0,1}};
        Dir[2] = {{-1,0},{1,0}};
        Dir[3] = {{0,-1},{1,0}};
        Dir[4] = {{0,1},{1,0}};
        Dir[5] = {{0,-1},{-1,0}};
        Dir[6] = {{0,1},{-1,0}};

        queue<pair<int, int>> Q;
        Q.push({0,0});

        vector<vector<bool>> Visited(Rows, vector<bool>(Cols));
        Visited[0][0] = true;

        while(!Q.empty())
        {
            auto[Row, Col] = Q.front();
            Q.pop();

            if(Row == Rows - 1 && Col == Cols - 1)
                return true;
            
            for(auto& [DR, DC] : Dir[grid[Row][Col]])
            {
                int DRow = Row + DR;
                int DCol = Col + DC;

                if(DRow < 0 || DRow >= Rows || DCol < 0 || DCol >= Cols || Visited[DRow][DCol])
                    continue;
                
                for(auto& [BDR, BDC] : Dir[grid[DRow][DCol]])
                {
                    if(DRow + BDR == Row && DCol + BDC == Col)
                    {
                        Visited[DRow][DCol] = true;
                        Q.push({DRow, DCol});
                    }
                }
            }
        }
        return false;
    }
};