class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        for (int row = (int)triangle.size() - 2; row >= 0; row--)
        {
            for (int col = 0; col < (int)triangle[row].size(); col++)
            {
                triangle[row][col] += min(triangle[row + 1][col], triangle[row + 1][col + 1]);
            }
        }
        return triangle[0][0];
    }
};