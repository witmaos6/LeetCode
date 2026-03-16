class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid)
    {
        const int Rows = static_cast<int>(grid.size());
        const int Cols = static_cast<int>(grid[0].size());

        set<int> Table;

        for(int i = 0; i < Rows; i++)
        {
            for(int j = 0; j < Cols; j++)
            {
                Table.insert(grid[i][j]);

                for(int k = 1; ; k++)
                {
                    int R = i + 2 * k;
                    int Left = j - k;
                    int Right = j + k;

                    if(R >= Rows || Left < 0 || Right >= Cols)
                        break;

                    int Sum = 0;
                    int X = i, Y = j;

                    for(int t = 0; t < k; t++)
                    {
                        Sum += grid[X + t][Y + t];
                    }

                    for(int t = 0; t < k; t++)
                    {
                        Sum += grid[X + k + t][Y + k - t];
                    }

                    for(int t = 0; t < k; t++)
                    {
                        Sum += grid[X + 2 * k - t][Y - t];
                    }

                    for(int t = 0; t < k; t++)
                    {
                        Sum += grid[X + k - t][Y - k + t];
                    }

                    Table.insert(Sum);
                }
            }
        }

        vector<int> Result;
        for(auto It = Table.rbegin(); It != Table.rend() && Result.size() < 3; ++It)
        {
            Result.push_back(*It);
        }
        return Result;
    }
};