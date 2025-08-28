class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid)
    {
        const int N = static_cast<int>(grid.size());
        for(int Row = N - 1; Row >= 0; Row--)
        {
            vector<int> Diagonal;
            int i = Row;
            int j = 0;
            while(i <= N - 1 && j <= N - 1)
            {
                Diagonal.push_back(grid[i][j]);
                i++;
                j++;
            }

            sort(Diagonal.begin(), Diagonal.end(), greater<>());
            i = Row;
            j = 0;
            while(i <= N - 1 && j <= N - 1)
            {
                grid[i][j] = Diagonal[j];
                j++;
                i++;
            }
        }

        for(int Col = N - 1; Col > 0; Col--)
        {
            vector<int> Diagonal;
            int i = 0;
            int j = Col;
            while(i <= N - 1 && j <= N - 1)
            {
                Diagonal.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(Diagonal.begin(), Diagonal.end());

            i = 0;
            j = Col;
            while(i <= N - 1 && j <= N - 1)
            {
                grid[i][j] = Diagonal[i];
                i++;
                j++;
            }
        }
        return grid;
    }
};