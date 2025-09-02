class Solution {
    static bool cmp(vector<int>& p, vector<int>& q){
        return (p[0]==q[0])?p[1]<q[1]:p[0]>q[0];// order by (x, >)
    }
public:
    int numberOfPairs(vector<vector<int>>& points)
    {
        sort(points.begin(), points.end(), cmp);
        const int N = static_cast<int>(points.size());
        int Count = 0;

        for(int i = 0; i < N - 1; i++)
        {
            int Y = INT_MAX;
            for(int j = i + 1; j < N; j++)
            {
                if(points[j][1] >= points[i][1] && Y > points[j][1])
                {
                    Count++;
                    Y = points[j][1];
                }
            }
        }
        return Count;
    }
};