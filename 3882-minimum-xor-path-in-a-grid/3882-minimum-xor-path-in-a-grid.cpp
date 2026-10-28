class Solution {
public:
    int minCost(vector<vector<int>>& grid)
    {
        const int Cols = grid[0].size();
        vector<bitset<1024>> Memo(Cols);

        Memo[0][0] = 1;
        for(vector<int>& Row : grid)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                bitset<1024> Reach = Col ? Memo[Col] | Memo[Col - 1] : Memo[Col];
                Memo[Col].reset();

                for(int X = 0; X < 1024; X++)
                {
                    if(Reach[X])
                    {
                        Memo[Col][X ^ Row[Col]] = 1;
                    }
                }
            }
        }
        int X = 0;
        while(!Memo[Cols - 1][X])
            X++;
        
        return X;
    }
};