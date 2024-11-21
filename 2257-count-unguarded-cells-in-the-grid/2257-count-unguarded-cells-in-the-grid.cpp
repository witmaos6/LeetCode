class Solution {
    vector<vector<char>> Matrix;  
    const char Stop = 'S';
    const char DG = 'd';
    const char Safe = 's';
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        Matrix.resize(m, vector<char>(n, Safe));
        for(vector<int>& Wall : walls)
        {
            Matrix[Wall[0]][Wall[1]] = Stop;
        }
        
        for(vector<int>& Guard : guards)
        {
            Matrix[Guard[0]][Guard[1]] = Stop;
        }

        for(vector<int>& Guard : guards)
        {
            int Row = Guard[0];
            int Col = Guard[1];
            
            Matrix[Row][Col] = Stop;
    
            for(int NorthRow = Row + 1; NorthRow < m; ++NorthRow)
            {
                if(Matrix[NorthRow][Col] == Stop)
                    break;

                Matrix[NorthRow][Col] = DG;            
            }

            for(int SouthRow = Row - 1; SouthRow >= 0; --SouthRow)
            {
                if(Matrix[SouthRow][Col] == Stop)
                    break;

                Matrix[SouthRow][Col] = DG;                
            }
            
            for(int EastCol = Col + 1; EastCol < n; ++EastCol)
            {
                if(Matrix[Row][EastCol] == Stop)
                    break;

                Matrix[Row][EastCol] = DG;                
            }
            
            for(int WestCol = Col - 1; WestCol >= 0; --WestCol)
            {
                if(Matrix[Row][WestCol] == Stop)
                break;
            
                Matrix[Row][WestCol] = DG;
            }
        }
        
        int Count = 0;
        for(vector<char>& Row : Matrix)
        {
            for(char& Col : Row)
            {
                if(Col == Safe)
                {
                    ++Count;
                }
            }
        }
        
        return Count;
    }
};