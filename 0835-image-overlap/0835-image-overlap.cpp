class Solution {
    int N = 0;
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2)
    {
        N = img1.size();

        int Result = 0;

        for(int Row = -N + 1; Row < N; Row++)
        {
            for(int Col = -N + 1; Col < N; Col++)
            {
                Result = max(Result, CountOverlap(img1, img2, Row, Col));
            }
        }
        return Result;
    }
private:
    int CountOverlap(vector<vector<int>>& Img1, vector<vector<int>>& Img2, int ShiftRow, int ShiftCol)
    {
        int Count = 0;

        for(int Row = 0; Row < N; Row++)
        {
            for(int Col = 0; Col < N; Col++)
            {
                if((N > Row + ShiftRow && Row + ShiftRow >= 0) && (N > Col + ShiftCol && Col + ShiftCol >= 0))
                {
                    if(Img1[Row + ShiftRow][Col + ShiftCol] & Img2[Row][Col])
                    {
                        Count++;
                    }
                }
            }
        }
        return Count;
    }
};