class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k)
    {
        const int Rows = grid.size();
        const int Cols = grid[0].size();

        vector<vector<vector<int>>> Memo(Rows, vector<vector<int>>(Cols, vector<int>(k + 1, -1)));
        Memo[0][0][0] = 0;

        for(int Row = 0; Row < Rows; Row++)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                for(int C = 0; C <= k; C++)
                {
                    if(Memo[Row][Col][C] == -1)
                        continue;
                    
                    if(Row + 1 < Rows)
                    {
                        int Value = grid[Row + 1][Col];
                        int Cost = (Value == 0 ? 0 : 1);

                        int Next = C + Cost;
                        if(Next <= k)
                        {
                            Memo[Row + 1][Col][Next] = max(Memo[Row + 1][Col][Next], Memo[Row][Col][C] + Value);
                        }
                    }

                    if(Col + 1 < Cols)
                    {
                        int Value = grid[Row][Col + 1];
                        int Cost = (Value == 0 ? 0 : 1);

                        int Next = C + Cost;
                        if(Next <= k)
                        {
                            Memo[Row][Col + 1][Next] = max(Memo[Row][Col + 1][Next], Memo[Row][Col][C] + Value);
                        }
                    }
                }
            }
        }

        int Result = -1;
        for(int C = 0; C <= k; C++)
        {
            Result = max(Result, Memo[Rows - 1][Cols - 1][C]);
        }
        return Result;
    }
};