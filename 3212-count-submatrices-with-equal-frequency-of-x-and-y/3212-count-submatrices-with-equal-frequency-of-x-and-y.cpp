class Solution {
    using Pair = pair<int, int>; // first is X Freq, second is Y Freq
public:
    int numberOfSubmatrices(vector<vector<char>>& grid)
    {
        const int Rows = static_cast<int>(grid.size());
        const int Cols = static_cast<int>(grid[0].size());
        vector<vector<Pair>> Memo(Rows, vector<Pair>(Cols, {0,0}));
        int Result = 0;

        for(int Row = 0; Row < Rows; Row++)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                Pair Curr = Memo[Row][Col];
                if(grid[Row][Col] == 'X')
                {
                    Curr.first++;
                }
                else if(grid[Row][Col] == 'Y')
                {
                    Curr.second++;
                }

                if(Row > 0)
                {
                    Add(Curr, Memo[Row - 1][Col]);
                }
                if(Col > 0)
                {
                    Add(Curr, Memo[Row][Col - 1]);
                }
                if(Row > 0 && Col > 0)
                {
                    Subtraction(Curr, Memo[Row - 1][Col - 1]);
                }

                if(Curr.first >= 1 && Curr.first == Curr.second)
                {
                    Result++;
                }
                Memo[Row][Col] = Curr;
            }
        }
        return Result;
    }

private:
    void Add(Pair& A, Pair& B)
    {
        A.first += B.first;
        A.second += B.second;
    }

    void Subtraction(Pair& A, Pair& B)
    {
        A.first -= B.first;
        A.second -= B.second;
    }
};