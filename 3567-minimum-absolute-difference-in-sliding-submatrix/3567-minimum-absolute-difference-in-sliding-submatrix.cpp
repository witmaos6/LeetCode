class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k)
    {
        const int Rows = static_cast<int>(grid.size());
        const int Cols = static_cast<int>(grid[0].size());
        vector<vector<int>> Result(Rows - k + 1, vector<int>(Cols - k + 1));
        map<int, int> Sub;

        for(int Row = 0; Row <= Rows - k; Row++)
        {
            for(int Col = 0; Col <= Cols - k; Col++)
            {
                if(Col == 0)
                {
                    Sub.clear();
                    BuildSubMat(Sub, grid, k, Row, Col);
                }
                else
                {
                    for(int i = Row; i < Row + k; i++)
                    {
                        int Temp = --Sub[grid[i][Col - 1]];
                        if(Temp == 0)
                            Sub.erase(grid[i][Col - 1]);
                    }
                    for(int i = Row; i < Row + k; i++)
                    {
                        Sub[grid[i][Col + k - 1]]++;
                    }
                }

                int Min = INT_MAX;
                for(auto It = Sub.begin(); It != Sub.end(); ++It)
                {
                    if(next(It) == Sub.end())
                        break;

                    int Diff = abs(It->first - next(It)->first);
                    Min = min(Min, Diff);
                }
                Result[Row][Col] = (Min == INT_MAX) ? 0 : Min;
            }
        }
        return Result;
    }
private:
    void BuildSubMat(map<int, int>& Sub, vector<vector<int>>& grid, int k, int Row, int Col)
    {
        for(int i = Row; i < Row + k; i++)
        {
            for(int j = Col; j < Col + k; j++)
            {
                Sub[grid[i][j]]++;
            }
        }
    }
};