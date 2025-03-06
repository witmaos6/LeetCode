class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid)
    {
        const int N = static_cast<int>(grid.size());
        vector<bool> Table(N * N + 1);
        int ExpectedTotal = pow(N, 2) * (pow(N, 2) + 1) / 2;
        int Total = 0;
        int TwiceNum = 0;
        for(int Row = 0; Row < N; Row++)
        {
            for(int Col = 0; Col < N; Col++)
            {
                if(Table[grid[Row][Col]])
                {
                    TwiceNum = grid[Row][Col];
                }
                Total += grid[Row][Col];
                Table[grid[Row][Col]] = true;
            }
        }

        vector<int> Result = {TwiceNum, TwiceNum + (ExpectedTotal - Total)};

        return Result;
    }
};