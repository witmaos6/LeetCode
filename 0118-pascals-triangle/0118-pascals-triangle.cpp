class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> Result(numRows);
        Result[0] = {1};
        if(numRows == 1)
        {
            return Result;
        }
        
        Result[1] = {1, 1};
        for(int i = 2; i < numRows; i++)
        {
            vector<int> Row(i + 1, 1);
            vector<int>& Floor = Result[i - 1];
            
            for(int j = 1; j < i; j++)
            {
                int Temp = Floor[j - 1] + Floor[j];
                Row[j] = Temp;
            }
            
            Result[i] = Row;
        }
        
        return Result;
    }
};