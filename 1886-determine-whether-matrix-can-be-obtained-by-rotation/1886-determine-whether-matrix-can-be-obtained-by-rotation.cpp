class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        const int N = static_cast<int>(mat.size());
        if(mat == target)
            return true;

        bool bPossible = true;
        int TRow = 0, TCol = 0;
        for(int Col = 0; Col < N; Col++)
        {
            TCol = 0;
            for(int Row = N - 1; Row >= 0; Row--)
            {
                if(mat[Row][Col] != target[TRow][TCol])
                {
                    bPossible = false;
                    break;
                }
                TCol++;
            }
            TRow++;
            if(bPossible == false)
                break;
        }

        if(bPossible)
            return true;

        TRow = 0, TCol = 0;
        bPossible = true;
        for(int Row = N - 1; Row >= 0; Row--)
        {
            TCol = 0;
            for(int Col = N - 1; Col >= 0; Col--)
            {
                if(mat[Row][Col] != target[TRow][TCol])
                {
                    bPossible = false;
                    break;
                }
                TCol++;
            }
            if(bPossible == false)
                break;
            TRow++;
        }

        if(bPossible)
            return true;

        bPossible = true;
        TRow = 0, TCol = 0;
        for(int Col = N - 1; Col >= 0; Col--)
        {
            TCol = 0;
            for(int Row = 0; Row < N; Row++)
            {
                if(mat[Row][Col] != target[TRow][TCol])
                {
                    bPossible = false;
                    break;
                }
                TCol++;
            }
            TRow++;
            if(bPossible == false)
                break;
        }

        return bPossible;
    }
};