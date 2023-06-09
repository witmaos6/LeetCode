class Solution {
    typedef pair<int, int> Point;
    const int Empty = 0;
    const int Orange = 1;
    const int Rotten = 2;
    const int ExistFreshOrange = -1;
    vector<Point> Dir = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int RowSize = 0;
    int ColSize = 0;
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        RowSize = static_cast<int>(grid.size());
        ColSize = static_cast<int>(grid[0].size());
        
        queue<Point> BFS;
        int NrOfOrange = 0;
        
        for(int Row = 0; Row < RowSize; Row++)
        {
            for(int Col = 0; Col < ColSize; Col++)
            {
                if(grid[Row][Col] == Rotten)
                {
                    BFS.push({Row, Col});
                }
                else if(grid[Row][Col] == Orange)
                {
                    NrOfOrange++;
                }
            }
        }
        if(NrOfOrange == 0)
            return 0;
        
        int Count = -1;
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            
            for(size_t i = 0; i < Range; i++)
            {
                Point CurrPoint = BFS.front();
                BFS.pop();

                for(Point& D : Dir)
                {
                    int Row = CurrPoint.first + D.first;
                    int Col = CurrPoint.second + D.second;

                    if(bInBoundary({Row, Col}) && grid[Row][Col] == Orange)
                    {
                        grid[Row][Col] = Rotten;
                        NrOfOrange--;
                        BFS.push({Row, Col});
                    }
                }
            }
            Count++;
        }
        
        if(NrOfOrange == 0)
        {
            return Count;
        }
        return ExistFreshOrange;
    }
    
private:
    bool bInBoundary(Point P)
    {
        if(P.first >= 0 && P.first < RowSize && P.second >= 0 && P.second < ColSize)
        {
            return true;
        }
        return false;
    }
};