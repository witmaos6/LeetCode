class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        const int Rows = static_cast<int>(mat.size());
        const int Cols = static_cast<int>(mat[0].size());
        vector<int> Result;
        Result.reserve(Rows * Cols);
        int Range = Rows * Cols;
        int Row = 0, Col = 0;
        for(int i = 0; i < Range; i++)
        {
            Result.push_back(mat[Row][Col]);

            if((Row + Col) % 2 == 0)
            {
                if(Col == Cols - 1)
                {
                    Row++;
                }
                else if(Row == 0)
                {
                    Col++;
                }
                else
                {
                    Row--;
                    Col++;
                }
            }
            else
            {
                if(Row == Rows - 1)
                {
                    Col++;
                }
                else if(Col == 0)
                {
                    Row++;
                }
                else
                {
                    Row++;
                    Col--;
                }
            }
        }
        return Result;
    }
};