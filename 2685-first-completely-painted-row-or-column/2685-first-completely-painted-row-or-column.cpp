class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
    {
        const int ArrSize = static_cast<int>(arr.size());
        const int Rows = static_cast<int>(mat.size());
        const int Cols = static_cast<int>(mat[0].size());

        vector<pair<int, int>> NumToCoordinate(Rows * Cols);
        
        for(int Row = 0; Row < Rows; Row++)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                NumToCoordinate[mat[Row][Col] - 1] = {Row, Col};
            }
        }

        vector<int> RowsMark(Rows);
        vector<int> ColsMark(Cols);

        for(int i = 0; i < ArrSize; i++)
        {
            auto[Row, Col] = NumToCoordinate[arr[i] - 1];
            RowsMark[Row]++;
            ColsMark[Col]++;
            if(RowsMark[Row] == Cols || ColsMark[Col] == Rows)
            {
                return i;
            }
        }

        return ArrSize - 1;
    }
};