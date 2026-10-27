class Solution {
public:
    vector<string> createGrid(int m, int n)
    {
        vector<string> Grid(m, string(n, '#'));
        for(int i = 0; i < n; i++)
        {
            Grid[0][i] = '.';
        }
        for(int i = 0; i < m; i++)
        {
            Grid[i][n - 1] = '.';
        }
        return Grid;
    }
};