class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat)
    {
        const int N = static_cast<int>(mat.size());
        const int Length = N - 1;
        
        int Sum = 0;
        
        for(int i = 0; i < N; i++)
        {
            if(i == Length - i)
            {
                Sum += mat[i][i];
            }
            else
            {
                Sum += (mat[i][i] + mat[i][Length - i]);
            }
        }
        
        return Sum;
    }
};