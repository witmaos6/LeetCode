class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix)
    {
        const int Rows = static_cast<int>(matrix.size());
        const int Cols = static_cast<int>(matrix[0].size());
        
        for(int Col = 0; Col < Cols; Col++)
        {
            for(int Row = 1; Row < Rows; Row++)
            {
                if(matrix[Row][Col] == 1)
                {
                    matrix[Row][Col] += matrix[Row - 1][Col];
                }
            }
        }
        
        int Result = 0;
        for(int Row = 0; Row < Rows; Row++)
        {
            sort(matrix[Row].begin(), matrix[Row].end(), greater<int>());
            
            for(int Col = 0; Col < Cols; Col++)
            {
                int Submatrix = matrix[Row][Col] * (Col + 1);
                Result = max(Result, Submatrix);
            }
        }
        return Result;
    }
};