class Solution {
    using Point = pair<int, int>;
    vector<Point> Dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int maximumSafenessFactor(vector<vector<int>>& grid)
    {
        if(grid.front().front() == 1 || grid.back().back() == 1)
            return 0;
        
        const int N = static_cast<int>(grid.size());
        vector<vector<int>> ManhattenDis(N, vector<int>(N, INT_MAX));
        
        BFS(grid, ManhattenDis, N);
        
        vector<vector<bool>> Visited(N, vector<bool>(N, false));
        priority_queue<pair<int, Point>> PQ;
        PQ.push({ManhattenDis[0][0], {0, 0}});
        
        while(!PQ.empty())
        {
            int CurrDis = PQ.top().first;
            auto[Row, Col] = PQ.top().second;
            PQ.pop();
            
            if(Row == N - 1 && Col == N - 1)
                return CurrDis;
            
            if(Visited[Row][Col])
                continue;
            
            Visited[Row][Col] = true;
            
            for(Point& D : Dir)
            {
                int DRow = Row + D.first;
                int DCol = Col + D.second;
                
                if(InBoundary(DRow, DCol, N))
                {
                    int MinDis = min(CurrDis, ManhattenDis[DRow][DCol]);
                    PQ.push({MinDis, {DRow, DCol}});
                }
            }
        }
        
        return 0;
    }
    
private:
    void BFS(vector<vector<int>>& Grid, vector<vector<int>>& ManhattenDis, const int N)
    {
        queue<Point> Q;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(Grid[i][j] == 1)
                {
                    Q.push({i, j});
                    ManhattenDis[i][j] = 0;
                }
            }
        }
        
        while(!Q.empty())
        {
            auto[Row, Col] = Q.front();
            Q.pop();
            int CurrDis = ManhattenDis[Row][Col];
            
            for(Point& D : Dir)
            {
                int DRow = Row + D.first;
                int DCol = Col + D.second;
                
                if(InBoundary(DRow, DCol, N) && ManhattenDis[DRow][DCol] > CurrDis + 1)
                {
                    Q.push({DRow, DCol});
                    ManhattenDis[DRow][DCol] = CurrDis + 1;
                }
            }
        }
    }
    
    bool InBoundary(const int Row, const int Col, const int N)
    {
        if(Row >= 0 && Row < N && Col >= 0 && Col < N)
            return true;
        
        return false;
    }
};