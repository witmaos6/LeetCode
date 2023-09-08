class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> Result = {{1}};
        if(numRows == 1)
        {
            return Result;
        }
        
        Result.push_back({1, 1});
        
        for(int i = 2; i < numRows; i++)
        {
            vector<int> Row = {1};
            
            for(int j = 1; j < i; j++)
            {
                int Temp = Result.back()[j - 1] + Result.back()[j];
                Row.push_back(Temp);
            }
            Row.push_back(1);
            
            Result.push_back(Row);
        }
        
        return Result;
    }
};