class Solution {
public:
    string decodeCiphertext(string encodedText, int rows)
    {
        const int N = encodedText.size();
        const int Cols = N / rows;
        vector<vector<char>> Cells(rows, vector<char>(Cols));

        for(int i = 0; i < rows; i++)
        {
            int ToCols = i * Cols;
            for(int j = 0; j < Cols; j++)
            {
                Cells[i][j] = encodedText[ToCols + j];
            }
        }

        string Result;
        for(int i = 0; i < Cols; i++)
        {
            int Row = 0;
            int Col = i;

            while(Row < rows && Col < Cols)
            {
                Result += Cells[Row][Col];
                Row++;
                Col++;
            }
        }

        while(!Result.empty() && Result.back() == ' ')
        {
            Result.pop_back();
        }
        return Result;
    }
};