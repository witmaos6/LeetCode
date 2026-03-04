class Solution {
public:
    int numSpecial(vector<vector<int>>& mat)
    {
        const int Rows = static_cast<int>(mat.size());
        const int Cols = static_cast<int>(mat[0].size());
        int Count = 0;

        for(int Row = 0; Row < Rows; Row++)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                if(mat[Row][Col] == 1)
                {
                    bool isSpecial = true;
                    for(int i = 0; i < Rows; i++)
                    {
                        if(mat[i][Col] == 1 && i != Row)
                        {
                            isSpecial = false;
                            break;
                        }
                    }
                    for(int i = 0; i < Cols; i++)
                    {
                        if(mat[Row][i] == 1 && i != Col)
                        {
                            isSpecial = false;
                            break;
                        }
                    }
                    if(isSpecial)
                    {
                        Count++;
                    }
                }
            }
        }
        return Count;
    }
};