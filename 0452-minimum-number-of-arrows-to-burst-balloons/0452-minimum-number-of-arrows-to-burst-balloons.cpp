class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        const int N = static_cast<int>(points.size());
        sort(points.begin(), points.end());
        
        int Arrow = 1;
        int LastEnd = points[0][1];
        
        for(int i = 1; i < N; i++)
        {
            if(points[i][0] > LastEnd)
            {
                Arrow++;
                LastEnd = points[i][1];
            }
            else
            {
                LastEnd = min(LastEnd, points[i][1]);
            }
        }
        
        return Arrow;
    }
};