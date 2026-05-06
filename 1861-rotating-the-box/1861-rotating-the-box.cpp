class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid)
    {
        const int Rows = static_cast<int>(boxGrid.size());
        const int Cols = static_cast<int>(boxGrid[0].size());
        
        vector<vector<char>> RotateBox(Cols, vector<char>(Rows, '.'));
        
        for(int Row = 0; Row < Rows; ++Row)
        {
            int i = Cols - 1;
            const int RotateCol = Rows - Row - 1;
            
            for(int Col = Cols - 1; Col >= 0; --Col)
            {
                if(boxGrid[Row][Col] == '#')
                {
                    RotateBox[i][RotateCol] = '#';
                    --i;
                }
                else if(boxGrid[Row][Col] == '*')
                {
                    RotateBox[Col][RotateCol] = '*';
                    i = Col - 1;
                }
            }
        }

        return RotateBox;
    }
};