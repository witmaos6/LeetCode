class Solution {
public:
    long long maxPoints(vector<vector<int>>& points)
    {
        const int Rows = static_cast<int>(points.size());
        const int Cols = static_cast<int>(points[0].size());
        vector<vector<long long>> Memo(2, vector<long long>(Cols));
        for(int i = 0; i < Cols; i++)
        {
            Memo[0][i] = points[0][i];
        }
        
        for(int Row = 1; Row < Rows; Row++)
        {
            vector<long long> Left(Cols);
            vector<long long> Right(Cols);
            
            Right[Cols - 1] = Memo[(Row - 1) & 1][Cols - 1];
            for(int Col = Cols - 2; Col >= 0; Col--)
            {
                Right[Col] = max(Right[Col + 1] - 1, Memo[(Row - 1) & 1][Col]);
            }
            
            Left[0] = Memo[(Row - 1) & 1][0];
            Memo[Row & 1][0] = max(Left[0], Right[0]) + points[Row][0];
            for(int Col = 1; Col < Cols; Col++)
            {
                Left[Col] = max(Left[Col - 1] - 1, Memo[(Row - 1) & 1][Col]);
                Memo[Row & 1][Col] = max(Left[Col], Right[Col]) + points[Row][Col];
            }
        }
        
        return *max_element(Memo[(Rows - 1) & 1].begin(), Memo[(Rows - 1) & 1].end());
    }
};