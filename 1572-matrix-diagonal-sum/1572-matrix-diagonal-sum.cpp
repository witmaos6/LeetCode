class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat)
    {
        const int N = static_cast<int>(mat.size());
        
        int Sum = 0;
        
        for(int i = 0; i < N; i++)
        {
            Sum += mat[i][i];
            mat[i][i] = 0;
        }
        
        int Row = N - 1, Col = 0;
        
        while(Col < N)
        {
            Sum += mat[Row][Col];
            Row--;
            Col++;
        }
        
        return Sum;
    }
};