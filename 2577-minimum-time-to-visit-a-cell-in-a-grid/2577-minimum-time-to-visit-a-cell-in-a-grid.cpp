class Solution {
    using Point = pair<int, int>;
    using Info = pair<int, Point>;
    int Rows = 0;
    int Cols = 0;
public:
    int minimumTime(vector<vector<int>>& grid)
    {
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        
        Rows = static_cast<int>(grid.size());
        Cols = static_cast<int>(grid[0].size());
        
        priority_queue<Info, vector<Info>, greater<Info>> Dijkstra;
        Dijkstra.push({0, {0, 0}});
        
        vector<vector<bool>> Visited(Rows, vector<bool>(Cols));
        Visited[0][0] = true;
        
        array<int, 5> Dir = {0,1,0,-1,0};
        
        while (!Dijkstra.empty())
        {
            int Time = Dijkstra.top().first;
            auto [Row, Col] = Dijkstra.top().second;
            Dijkstra.pop();
            
            if (Row == Rows - 1 && Col == Cols - 1) 
                return Time;
            
            for(int i = 0; i < 4; ++i)
            {
                int DRow = Row + Dir[i];
                int DCol = Col + Dir[i + 1];
                
                if(InBoundary(DRow, DCol) && !Visited[DRow][DCol])
                {
                    int WaitTime = ((grid[DRow][DCol] - Time) % 2 == 0) ? 1 : 0;
                    int NextTime = max(Time + 1, grid[DRow][DCol] + WaitTime);
                    
                    Dijkstra.push({NextTime, {DRow, DCol}});
                    Visited[DRow][DCol] = true;
                }
            }
        }
        
        return -1;
    }
private:
    bool InBoundary(const int Row, const int Col)
    {
        if(Row >= 0 && Row < Rows && Col >= 0 && Col < Cols)
            return true;
        
        return false;
    }
};