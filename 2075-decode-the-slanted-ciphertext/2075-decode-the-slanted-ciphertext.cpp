class Solution {
public:
    string decodeCiphertext(string encodedText, int rows)
    {
        const int N = encodedText.size();
        const int Cols = N / rows;

        string Result;
        Result.reserve(Cols);
        for(int i = 0; i < Cols; i++)
        {
            for(int j = 0; j < rows; j++)
            {
                int ToCol = i + j;
                if(ToCol >= Cols)
                    break;

                Result += encodedText[j * Cols + ToCol];
            }
        }

        while(!Result.empty() && Result.back() == ' ')
        {
            Result.pop_back();
        }
        
        return Result;
    }
};