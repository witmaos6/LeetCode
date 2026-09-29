class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid)
    {
        const int Rows = grid.size();
        const int Cols = grid[0].size();
        int Length = Rows + Cols - 1;

        if(grid[0][0] == ')' || (Length & 1) || grid[Rows - 1][Cols - 1] == '(')
            return false;

        vector<bitset<201>> Memo(Cols);

        for(int Row = 0; Row < Rows; Row++)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                bitset<201> Reach;

                if(Row > 0)
                    Reach |= Memo[Col];
                if(Col > 0)
                    Reach |= Memo[Col - 1];
                if(Row == 0 && Col == 0)
                    Reach.set(0);
                
                Memo[Col] = grid[Row][Col] == '(' ? (Reach << 1) : (Reach >> 1);
            }
        }
        return Memo[Cols - 1].test(0);
    }
};