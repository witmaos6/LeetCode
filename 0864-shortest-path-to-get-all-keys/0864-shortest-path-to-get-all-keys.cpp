class Solution {
    typedef pair<int, int> Point;
    const char Cell = '.';
    const char Wall = '#';
    const char Start = '@';
    const int TransLock = 'a' - 'A';
    
    int RowSize;
    int ColSize;
public:
    int shortestPathAllKeys(vector<string>& grid)
    {
        RowSize = static_cast<int>(grid.size());
        ColSize = static_cast<int>(grid[0].size());
        
        Point Begin;
        int NrOfKey = 0;
        
        for(int Row = 0; Row < RowSize; Row++)
        {
            for(int Col = 0; Col < ColSize; Col++)
            {
                if(grid[Row][Col] == Start)
                {
                    Begin.first = Row;
                    Begin.second = Col;
                }
                else if(bIsKey(grid[Row][Col]))
                {
                    NrOfKey++;
                }
            }
        }
        
        int Mask = (1 << NrOfKey) - 1;
        unordered_map<int, set<int>> Visited;
        Visited[Begin.first * ColSize + Begin.second].insert(Mask);
        
        queue<Point> BFS;
        BFS.push({Begin.first * ColSize + Begin.second, Mask});
        vector<int> Dir = {1,0,-1,0,1};
        
        int Result = 0;
        
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            
            while(Range--)
            {
                Point P = BFS.front();
                BFS.pop();
                
                int Row = P.first / ColSize;
                int Col = P.first % ColSize;
                
                Mask = P.second;
                
                if(bIsKey(grid[Row][Col]))
                {
                    if(Mask & (1 << (grid[Row][Col] - 'a')))
                    {
                        Mask -= (1 << (grid[Row][Col] - 'a'));
                    }
                }
                
                if(Mask == 0)
                    return Result;
                
                for(int i = 0; i < 4; i++)
                {
                    int DRow = Row + Dir[i];
                    int DCol = Col + Dir[i + 1];
                    
                    if(!bInBoundary(DRow, DCol) || grid[DRow][DCol] == Wall)
                        continue;
                    
                    if(bIsLock(grid[DRow][DCol]) && 
                       (Mask & (1<<(grid[DRow][DCol]-'A'))))
                        continue;
                    
                    int Key = (DRow * ColSize) + DCol;
                    
                    if(Visited[Key].find(Mask) == Visited[Key].end())
                    {
                        BFS.push({Key, Mask});
                        Visited[Key].insert(Mask);
                    }
                }
            }
            Result++;
        }
        
        return -1;
    }
    
private:
    bool bInBoundary(int Row, int Col)
    {
        if(Row >= 0 && Row < RowSize && Col >= 0 && Col < ColSize)
        {
            return true;
        }
        return false;
    }
    
    bool bIsKey(char C)
    {
        return (C >= 'a' && C <= 'z');
    }
    
    bool bIsLock(char C)
    {
        return (C >= 'A' && C <= 'Z');
    }
};