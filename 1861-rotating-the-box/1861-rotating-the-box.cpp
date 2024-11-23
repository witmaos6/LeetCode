class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box)
    {
        const int Rows = static_cast<int>(box.size());
        const int Cols = static_cast<int>(box[0].size());
        
        vector<vector<char>> RotateBox(Cols, vector<char>(Rows, '.'));
        
        for(int Row = 0; Row < Rows; ++Row)
        {
            int i = Cols - 1;
            int RotateCol = Rows - Row - 1;
            
            for(int Col = Cols - 1; Col >= 0; --Col)
            {
                if(box[Row][Col] == '#')
                {
                    RotateBox[i][RotateCol] = '#';
                    --i;
                }
                else if(box[Row][Col] == '*')
                {
                    RotateBox[Col][RotateCol] = '*';
                    i = Col - 1;
                }
            }
        }

        return RotateBox;
    }
};