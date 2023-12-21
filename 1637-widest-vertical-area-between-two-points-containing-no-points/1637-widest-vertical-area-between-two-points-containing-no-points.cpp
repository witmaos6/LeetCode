class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points)
    {
        sort(points.begin(), points.end(), [](const vector<int>& A, const vector<int>& B)
        {
            return A[0] < B[0];
        });
        
        const size_t N = points.size();
        int MaxWidth = 0;
        for(size_t i = 1; i < N; i++)
        {
            MaxWidth = max(MaxWidth, points[i][0] - points[i - 1][0]);
        }
        
        return MaxWidth;
    }
};