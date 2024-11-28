class Solution {
    using Point = pair<int, int>;
    using Info = pair<int, Point>;
    int Rows = 0;
    int Cols = 0;
    array<int, 5> Dir = {-1,0,1,0,-1};
public:
    int minimumObstacles(vector<vector<int>>& grid)
    {
        Rows = static_cast<int>(grid.size());
        Cols = static_cast<int>(grid[0].size());
        
        vector<vector<int>> RemoveObstacle(Rows, vector<int>(Cols, INT_MAX));
        
        priority_queue<Info, vector<Info>, greater<Info>> BFS;
        BFS.push({0, {0, 0}});
        
        while(!BFS.empty())
        {
            int RemoveCount = BFS.top().first;
            auto [Row, Col] = BFS.top().second;
            BFS.pop();
            
            if(RemoveObstacle[Row][Col] <= RemoveCount)
            {
                continue;
            }
            
            RemoveObstacle[Row][Col] = RemoveCount;
            if(Row == Rows - 1 && Col == Cols - 1)
            {
                break;
            }

            for(int i = 0; i < 4; ++i)
            {
                int DRow = Row + Dir[i];
                int DCol = Col + Dir[i + 1];
                
                if(InBoundary(DRow, DCol))
                {
                    int UpdateRemoveCount = RemoveCount + (grid[DRow][DCol] == 1);
                    BFS.push({UpdateRemoveCount, {DRow, DCol}});
                }
            }
        }
        
        return RemoveObstacle[Rows - 1][Cols - 1];
    }
private:
    bool InBoundary(const int Row, const int Col)
    {
        if(Row >= 0 && Row < Rows && Col >= 0 && Col < Cols)
            return true;
        
        return false;
    }
};