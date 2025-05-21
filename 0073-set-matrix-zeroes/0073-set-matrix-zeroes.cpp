class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        const int Rows = static_cast<int>(matrix.size());
        const int Cols = static_cast<int>(matrix[0].size());

        bool FirstRowZero = false;
        bool FirstColZero = false;

        for(int i = 0; i < Rows; i++)
        {
            if(matrix[i][0] == 0)
            {
                FirstColZero = true;
                break;
            }
        }
        for(int i = 0; i < Cols; i++)
        {
            if(matrix[0][i] == 0)
            {
                FirstRowZero = true;
                break;
            }
        }

        for(int i = 1; i < Rows; i++)
        {
            for(int j = 1; j < Cols; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int Row = 1; Row < Rows; Row++)
        {
            if(matrix[Row][0] == 0)
            {
                for(int Col = 1; Col < Cols; Col++)
                {
                    matrix[Row][Col] = 0;
                }
            }
        }
        for(int Col = 1; Col < Cols; Col++)
        {
            if(matrix[0][Col] == 0)
            {
                for(int Row = 1; Row < Rows; Row++)
                {
                    matrix[Row][Col] = 0;
                }
            }
        }

        if(FirstRowZero)
        {
            for(int i = 0; i < Cols; i++)
            {
                matrix[0][i] = 0;
            }
        }
        if(FirstColZero)
        {
            for(int i = 0; i < Rows; i++)
            {
                matrix[i][0] = 0;
            }
        }
        
    }
};