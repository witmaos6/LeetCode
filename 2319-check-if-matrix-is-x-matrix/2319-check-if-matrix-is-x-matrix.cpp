class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid)
    {
        const int N = static_cast<int>(grid.size());
        const int Length = N - 1;
        
        for(int Row = 0; Row < N; Row++)
        {
            for(int Col = 0; Col < N; Col++)
            {
                if(Row == Col)
                {
                    if(grid[Row][Col] == 0)
                        return false;
                }
                else if(Length - Row == Col)
                {
                    if(grid[Row][Col] == 0)
                        return false;
                }
                else if(grid[Row][Col] != 0)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};