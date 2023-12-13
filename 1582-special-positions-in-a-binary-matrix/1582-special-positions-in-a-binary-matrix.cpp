class Solution {
public:
    int numSpecial(vector<vector<int>>& mat)
    {
        const int RowSize = static_cast<int>(mat.size());
        const int ColSize = static_cast<int>(mat[0].size());
        
        int CountSpecial = 0;
        for(int Row = 0; Row < RowSize; Row++)
        {
            for(int Col = 0; Col < ColSize; Col++)
            {
                if(mat[Row][Col] == 1)
                {
                    if(ExistRowOne(mat[Row], Col, ColSize))
                    {
                        break;
                    }
                    
                    int CountCol = 0;
                    for(int i = 0; i < RowSize; i++)
                    {
                        if(mat[i][Col] == 1)
                        {
                            CountCol++;
                            
                            if(CountCol > 1)
                                break;
                        }
                    }
                    
                    if(CountCol == 1)
                    {
                        CountSpecial++;
                        break;
                    }
                }
            }
        }
        
        return CountSpecial;
    }
    
private:
    bool ExistRowOne(vector<int>& Mat, int Col, const int ColSize)
    {
        for(int i = Col + 1; i < ColSize; i++)
        {
            if(Mat[i] == 1)
            {
                return true;
            }
        }
        return false;
    }
};