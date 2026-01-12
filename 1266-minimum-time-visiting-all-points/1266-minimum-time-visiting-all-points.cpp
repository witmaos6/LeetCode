class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points)
    {
        const int N = static_cast<int>(points.size());

        int Result = 0;
        for(int i = 1; i < N; i++)
        {
            Result += GetDist(points[i - 1], points[i]);
        }
        return Result;
    }
private:
    int GetDist(vector<int>& From, vector<int>& To)
    {
        int X = abs(From[0] - To[0]);
        int Y = abs(From[1] - To[1]);
        return max(X, Y);
    }
};