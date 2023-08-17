class Solution {
    typedef pair<int, int> Point;
    
    int RowSize = 0;
    int ColSize = 0;
    queue<Point> BFS;
    
    vector<Point> Dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        RowSize = static_cast<int>(mat.size());
        ColSize = static_cast<int>(mat[0].size());
        
        for(int Row = 0; Row < RowSize; Row++)
        {
            for(int Col = 0; Col < ColSize; Col++)
            {
                if(mat[Row][Col] == 0)
                {
                    BFS.push({Row, Col});
                }
                else
                {
                    mat[Row][Col] = INT_MAX;
                }
            }
        }
        
        SetNearestDistance(mat);
        
        return mat;
    }
    
private:
    void SetNearestDistance(vector<vector<int>>& Mat)
    {
        int Distance = 0;
        
        while(!BFS.empty())
        {
            auto [Row, Col] = BFS.front();
            BFS.pop();

            for(auto [DR, DC] : Dir)
            {
                int DRow = Row + DR;
                int DCol = Col + DC;

                if(!InBoundary(DRow, DCol))
                {
                    continue;
                }
                
                if(Mat[DRow][DCol] > Mat[Row][Col] + 1)
                {
                    BFS.push({DRow, DCol});
                    Mat[DRow][DCol] = Mat[Row][Col] + 1;
                }
            }
        }
    }
    
    bool InBoundary(int Row, int Col)
    {
        if(Row >= 0 && Row < RowSize && Col >= 0 && Col < ColSize)
        {
            return true;
        }
        return false;
    }
};