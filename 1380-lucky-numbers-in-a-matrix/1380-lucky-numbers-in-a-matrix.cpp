class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix)
    {
        const int Rows = static_cast<int>(matrix.size());
        const int Cols = static_cast<int>(matrix[0].size());
        
        vector<int> Result;
        for(int Row = 0; Row < Rows; Row++)
        {
            int MinNumInCol = INT_MAX;
            int MinNumIndex = 0;
            for(int Col = 0; Col < Cols; Col++)
            {
                if(MinNumInCol > matrix[Row][Col])
                {
                    MinNumInCol = matrix[Row][Col];
                    MinNumIndex = Col;
                }
            }
            
            bool Flag = true;
            for(int i = 0; i < Rows; i++)
            {
                if(MinNumInCol < matrix[i][MinNumIndex])
                {
                    Flag = false;
                    break;
                }
            }
            
            if(Flag)
            {
                Result.push_back(MinNumInCol);
            }
        }
        
        return Result;
    }
};