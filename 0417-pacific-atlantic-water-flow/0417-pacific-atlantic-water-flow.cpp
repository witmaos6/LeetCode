class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        const int Rows = static_cast<int>(heights.size());
        const int Cols = static_cast<int>(heights[0].size());

        vector<vector<bool>> Pacific(Rows, vector<bool>(Cols, false));
        vector<vector<bool>> Atlantic(Rows, vector<bool>(Cols, false));

        for(int i = 0; i < Rows; i++)
        {
            Pacific[i][0] = true;
            Atlantic[i][Cols - 1] = true;
        }
        for(int j = 0; j < Cols; j++)
        {
            Pacific[0][j] = true;
            Atlantic[Rows - 1][j] = true;
        }

        bool Updated = true;

        while(Updated)
        {
            Updated = false;
            for(int i = 0; i < Rows; i++)
            {
                for(int j = 0; j < Cols; j++)
                {
                    if (!Pacific[i][j]) {
                        if (i > 0 && Pacific[i-1][j] && heights[i][j] >= heights[i-1][j]) {
                            Pacific[i][j] = true;
                            Updated = true;
                        } else if (i < Rows - 1 && Pacific[i+1][j] && heights[i][j] >= heights[i+1][j]) {
                            Pacific[i][j] = true;
                            Updated = true;
                        } else if (j > 0 && Pacific[i][j-1] && heights[i][j] >= heights[i][j-1]) {
                            Pacific[i][j] = true;
                            Updated = true;
                        } else if (j < Cols - 1 && Pacific[i][j+1] && heights[i][j] >= heights[i][j+1]) {
                            Pacific[i][j] = true;
                            Updated = true;
                        }
                    }
                    
                    if (!Atlantic[i][j]) {
                        if (i > 0 && Atlantic[i-1][j] && heights[i][j] >= heights[i-1][j]) {
                            Atlantic[i][j] = true;
                            Updated = true;
                        } else if (i < Rows - 1 && Atlantic[i+1][j] && heights[i][j] >= heights[i+1][j]) {
                            Atlantic[i][j] = true;
                            Updated = true;
                        } else if (j > 0 && Atlantic[i][j-1] && heights[i][j] >= heights[i][j-1]) {
                            Atlantic[i][j] = true;
                            Updated = true;
                        } else if (j < Cols - 1 && Atlantic[i][j+1] && heights[i][j] >= heights[i][j+1]) {
                            Atlantic[i][j] = true;
                            Updated = true;
                        }
                    }
                }
            }
        }

        vector<vector<int>> Result;
        for(int i = 0; i < Rows; i++)
        {
            for(int j = 0; j < Cols; j++)
            {
                if(Pacific[i][j] && Atlantic[i][j])
                {
                    Result.push_back({i, j});
                }
            }
        }
        return Result;
    }
};