class Solution {
public:
    int numSubmat(vector<vector<int>>& mat)
    {
        const int Rows = static_cast<int>(mat.size());
        const int Cols = static_cast<int>(mat[0].size());
        int Result = 0;
        vector<int> Memo(Cols);
        for(int i = 0; i < Rows; i++)
        {
            for(int j = 0; j < Cols; j++)
            {
                Memo[j] = mat[i][j] ? Memo[j] + 1 : 0;
            }

            vector<int> Sum(Cols);
            stack<int> St;

            for(int j = 0; j < Cols; j++)
            {
                while(!St.empty() && Memo[St.top()] >= Memo[j])
                    St.pop();

                if(!St.empty())
                {
                    int P = St.top();
                    Sum[j] = Sum[P] + Memo[j] * (j - P);
                }
                else
                {
                    Sum[j] = Memo[j] * (j + 1);
                }
                St.push(j);
                Result += Sum[j];
            }
        }
        return Result;
    }
};