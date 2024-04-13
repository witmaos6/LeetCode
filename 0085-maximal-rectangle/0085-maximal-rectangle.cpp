class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        const int Rows = static_cast<int>(matrix.size());
        const int Cols = static_cast<int>(matrix[0].size());
        vector<int> Heights(Cols + 1, 0);
        const int HeightsSize = Cols + 1;
        int MaxArea = 0;

        for (vector<char>& Row : matrix)
        {
            for (int i = 0; i < Cols; i++)
            {
                Heights[i] = (Row[i] == '1') ? Heights[i] + 1 : 0;
            }

            stack<int> St;
            for (int i = 0; i < HeightsSize; i++)
            {
                while (!St.empty() && Heights[i] < Heights[St.top()])
                {
                    int H = Heights[St.top()];
                    St.pop();
                    int W = St.empty() ? i : i - St.top() - 1;
                    MaxArea = max(MaxArea, H * W);
                }
                St.push(i);
            }
        }

        return MaxArea;
    }
};