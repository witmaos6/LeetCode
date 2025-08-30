class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        vector<set<char>> Rows(9), Cols(9), Blocks(9);

        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                {
                    continue;
                }
                char CurrentNumber = board[row][col];
                if (Rows[row].count(CurrentNumber) ||
                    Cols[col].count(CurrentNumber) ||
                    Blocks[(row / 3) * 3 + col / 3].count(CurrentNumber))
                {
                    return false;
                }

                Rows[row].insert(CurrentNumber);
                Cols[col].insert(CurrentNumber);
                Blocks[(row / 3) * 3 + col / 3].insert(CurrentNumber);
            }
        }
        return true;
    }
};