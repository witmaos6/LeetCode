class Solution {
    int N = 0;
public:
    int largestIsland(vector<vector<int>>& grid)
    {
        N = static_cast<int>(grid.size());

        vector<vector<int>> Memo(N, vector<int>(N));
        unordered_map<int, int> IslandSize;
        int Label = 1;
        int MaxSize = 0;

        array<int, 5> Dir = {-1,0,1,0,-1};

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(grid[i][j] == 1 && Memo[i][j] == 0)
                {
                    int Size = 0;
                    vector<pair<int, int>> Stack;
                    Stack.push_back({i,j});
                    Memo[i][j] = Label;

                    while(!Stack.empty())
                    {
                        auto[Row, Col] = Stack.back();
                        Stack.pop_back();
                        Size++;

                        for(int i = 0; i < 4; i++)
                        {
                            int DRow = Row + Dir[i];
                            int DCol = Col + Dir[i + 1];

                            if(InBoundary(DRow, DCol) && grid[DRow][DCol] == 1 && Memo[DRow][DCol] == 0)
                            {
                                Memo[DRow][DCol] = Label;
                                Stack.push_back({DRow, DCol});
                            }
                        }
                    }

                    IslandSize[Label] = Size;
                    MaxSize = max(MaxSize, Size);
                    Label++;
                }
            }
        }

        for(int Row = 0; Row < N; Row++)
        {
            for(int Col = 0; Col < N; Col++)
            {
                if(grid[Row][Col] == 0)
                {
                    unordered_set<int> AdjLabels;
                    int Total = 1;

                    for(int i = 0; i < 4; i++)
                    {
                        int DRow = Row + Dir[i];
                        int DCol = Col + Dir[i + 1];

                        if(InBoundary(DRow, DCol) && grid[DRow][DCol] == 1)
                        {
                            AdjLabels.insert(Memo[DRow][DCol]);
                        }
                    }

                    for(const int& Adj : AdjLabels)
                    {
                        Total += IslandSize[Adj];
                    }

                    MaxSize = max(MaxSize, Total);
                }
            }
        }
        return MaxSize;
    }
private:
    bool InBoundary(const int Row, const int Col)
    {
        if(Row >= 0 && Row < N && Col >= 0 && Col < N)
            return true;

        return false;
    }
};