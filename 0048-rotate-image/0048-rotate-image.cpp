class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        const int N = matrix.size();
        for (int Row = 0; Row < N; Row++)
        {
            for (int Col = Row; Col < N; Col++)
            {
                swap(matrix[Row][Col], matrix[Col][Row]);
            }
        }

        for (int Row = 0; Row < N; Row++)
        {
            int Left = 0, Right = N - 1;
            while (Left < Right)
            {
                swap(matrix[Row][Left], matrix[Row][Right]);
                ++Left;
                --Right;
            }
        }
    }
};