class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points)
    {
        const int N = static_cast<int>(points.size());

        double MaxArea = 0;
        for(int i = 0; i < N - 2; i++)
        {
            const int X = points[i][0], Y = points[i][1];
            for(int j = i + 1; j < N - 1; j++)
            {
                for(int k = j + 1; k < N; k++)
                {
                    double Area = 0.5 * ((points[j][0] - X) * (points[k][1] - Y) - (points[j][1] - Y) * (points[k][0] - X));
                    if(Area < 0)
                    {
                        Area = -Area;
                    }
                    MaxArea = max(MaxArea, Area);
                }
            }
        }
        return MaxArea;
    }
};