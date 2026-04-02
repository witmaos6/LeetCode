class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins)
    {
        const int Rows = coins.size();
        const int Cols = coins[0].size();

        vector Memo(Rows, vector(Cols, vector<int>(3, -1e9)));
        Memo[0][0][1] = Memo[0][0][2] = 0;
        Memo[0][0][0] = coins[0][0];

        for(int i = 0; i < Rows; i++)
        {
            for(int j = 0; j < Cols; j++)
            {
                for(int k = 0; k < 3; k++)
                {
                    if(i > 0)
                        Memo[i][j][k] = max(Memo[i][j][k], Memo[i - 1][j][k] + coins[i][j]);
                    if(i > 0 && k > 0)
                        Memo[i][j][k] = max(Memo[i][j][k], Memo[i - 1][j][k - 1]);
                    if(j > 0)
                        Memo[i][j][k] = max(Memo[i][j][k], Memo[i][j - 1][k] + coins[i][j]);
                    if(j > 0 && k > 0)
                        Memo[i][j][k] = max(Memo[i][j][k], Memo[i][j - 1][k - 1]);
                }
            }
        }
        int Result = *max_element(Memo[Rows - 1][Cols - 1].begin(), Memo[Rows - 1][Cols - 1].end());
        return Result;
    }
};