class Solution {
public:
    string decodeCiphertext(string encodedText, int rows)
    {
        const int N = encodedText.size();
        const int Cols = N / rows;
        string Result;

        for(int i = 0; i < Cols; i++)
        {
            Result += encodedText[i];
            for(int j = 1; j < rows; j++)
            {
                int ToCol = j * (Cols + 1);
                if(i + ToCol >= N)
                    break;

                Result += encodedText[i + ToCol];
            }
        }

        while(!Result.empty() && Result.back() == ' ')
        {
            Result.pop_back();
        }
        
        return Result;
    }
};