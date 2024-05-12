class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid)
    {
        const int N = static_cast<int>(grid.size());
        
        vector<vector<int>> Result(N - 2);
        for(int i = 0; i < N - 2; i++)
        {
            for(int j = 0; j < N - 2; j++)
            {
                int Rows = i + 3;
                int Cols = j + 3;
                int MaxValue = INT_MIN;
                for(int Row = i; Row < Rows; Row++)
                {
                    for(int Col = j; Col < Cols; Col++)
                    {
                        MaxValue = max(MaxValue, grid[Row][Col]);
                    }
                }
                Result[i].push_back(MaxValue);
            }
        }
        return Result;
    }
};