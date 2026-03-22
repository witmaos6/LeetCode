class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        const int N = static_cast<int>(mat.size());

        for(int i = 0; i < 4; i++)
        {
            if(mat == target)
                return true;

            for(int i = 0; i < N; i++)
            {
                for(int j = i; j < N; j++)
                {
                    swap(mat[i][j], mat[j][i]);
                }
            }

            for(int i = 0; i < N; i++)
            {
                reverse(mat[i].begin(), mat[i].end());
            }
        }
        return false;
    }
};