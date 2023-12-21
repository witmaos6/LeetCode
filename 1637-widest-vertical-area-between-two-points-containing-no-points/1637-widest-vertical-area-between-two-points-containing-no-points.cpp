class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points)
    {
        const size_t N = points.size();
        
        vector<int> XPoints(N);
        for(size_t i = 0; i < N; i++)
        {
            XPoints[i] = points[i][0];
        }
        
        sort(XPoints.begin(), XPoints.end());
        int MaxWidth = 0;
        
        for(size_t i = 1; i < N; i++)
        {
            MaxWidth = max(MaxWidth, XPoints[i] - XPoints[i - 1]);
        }
        
        return MaxWidth;
    }
};