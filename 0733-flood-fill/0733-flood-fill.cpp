class Solution {
    int RowSize = 0;
    int ColSize = 0;
    int OriginColor = 0;
    int FillColor = 0;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        if(image[sr][sc] == color)
        {
            return image;
        }
        
        RowSize = static_cast<int>(image.size());
        ColSize = static_cast<int>(image[0].size());
        OriginColor = image[sr][sc];
        FillColor = color;
        
        DFS(image, sr, sc);
        
        return image;
    }
    
private:
    void DFS(vector<vector<int>>& image, int Row, int Col)
    {
        if(bValidBoundary(Row, Col) && image[Row][Col] == OriginColor)
        {
            image[Row][Col] = FillColor;
            
            DFS(image, Row + 1, Col);
            DFS(image, Row - 1, Col);
            DFS(image, Row, Col + 1);
            DFS(image, Row, Col - 1);
        }
    }
    
    bool bValidBoundary(int Row, int Col)
    {
        if(Row >= 0 && Row < RowSize && Col >= 0 && Col < ColSize)
        {
            return true;
        }
        return false;
    }
};