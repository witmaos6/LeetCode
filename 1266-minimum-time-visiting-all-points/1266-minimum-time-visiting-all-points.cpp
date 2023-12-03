class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points)
    {
        const int N = static_cast<int>(points.size());
        
        int Time = 0;
        for(int i = 1; i < N; i++)
        {
            Time += GetTime(points[i - 1], points[i]);
        }
        
        return Time;
    }
    
private:
    int GetTime(vector<int>& From, vector<int>& To)
    {
        int XDist = abs(From[0] - To[0]);
        int YDist = abs(From[1] - To[1]);
        
        return max(XDist, YDist);
    }
};