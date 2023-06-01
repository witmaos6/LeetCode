class Solution {
    typedef pair<int, int> Point;
    
    const int NoClear = -1;
    const int Path = 0;
    const int Block = 1;
    int N = 0;
    vector<Point> Dir = {{1,0},{-1,0},{0,1},{0,-1}};
    queue<Point> BFS;
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& Grid)
    {
        N = static_cast<int>(Grid.size());
        
        if(Grid[0][0] == Block)
        {
            return NoClear;
        }
        
        BFS.push({0,0});
        int Count = 1;
        
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            
            for(size_t i = 0; i < Range; i++)
            {
                Point CurrPoint = BFS.front();
                BFS.pop();
                
                if(CurrPoint.first == N - 1 && CurrPoint.second == N - 1)
                    return Count;
                
                SetNextPoint(CurrPoint, Grid);
            }
            Count++;
        }
        
        return NoClear;
    }
    
private:
    void SetNextPoint(Point P, vector<vector<int>>& Grid)
    {
        for(int i = 0; i < 4; i++)
        {
            int DRow = P.first + Dir[i].first;
            int DCol = P.second + Dir[i].second;
            
            if(bInBoundary({DRow, DCol}) && Grid[DRow][DCol] == Path)
            {
                BFS.push({DRow, DCol});
                Grid[DRow][DCol] = Block;
            }
        }
        
        for(int i = 0; i <= 1; i++)
        {
            for(int j = 2; j <= 3; j++)
            {
                int DRow = P.first + Dir[i].first;
                int DCol = P.second + Dir[j].second;
                
                if(bInBoundary({DRow, DCol}) && Grid[DRow][DCol] == Path)
                {
                    BFS.push({DRow, DCol});
                    Grid[DRow][DCol] = Block;
                }
            }
        }
    }
    
    bool bInBoundary(const Point& P)
    {
        if(P.first >= 0 && P.first < N && P.second >= 0 && P.second < N)
        {
            return true;
        }
        return false;
    }
};