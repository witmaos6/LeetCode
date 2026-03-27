class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k)
    {
        const int Rows = mat.size();
        const int Cols = mat[0].size();

        k %= Cols;

        if(k == 0)
            return 1;

        for(int i = 0; i < Rows; i++)
        {
            bool iEven = (i & 1) == 0;
            for(int j = 0; j < Cols; j++)
            {
                int Index = (j + (iEven ? Cols - k : k)) % Cols;
                if(mat[i][j] != mat[i][Index])
                    return false;
            }
        }
        return true;
    }
};