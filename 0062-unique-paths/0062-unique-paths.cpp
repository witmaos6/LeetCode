class Solution {
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> Matrix(m, vector<int>(n));
        for(int Row = 0; Row < m; Row++)
        {
            Matrix[Row][0] = 1;
        }
        for(int Col = 0; Col < n; Col++)
        {
            Matrix[0][Col] = 1;
        }
        
        for(int Row = 1; Row < m; Row++)
        {
            for(int Col = 1; Col < n; Col++)
            {
                Matrix[Row][Col] = Matrix[Row - 1][Col] + Matrix[Row][Col - 1];
            }
        }
        
        return Matrix[m - 1][n - 1];
    }
};