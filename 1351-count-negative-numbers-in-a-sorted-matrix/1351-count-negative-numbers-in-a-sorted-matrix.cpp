class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        const int Rows = static_cast<int>(grid.size());
        const int Cols = static_cast<int>(grid[0].size());

        int Count = 0;
        for(int i = 0; i < Rows; i++)
        {
            int Index = lower_bound(grid[i].begin(), grid[i].end(), -1, greater<int>()) - grid[i].begin();

            Count += (Cols - Index);
        }
        return Count;
    }
};