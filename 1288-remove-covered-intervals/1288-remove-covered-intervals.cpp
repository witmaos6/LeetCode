class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int>& A, vector<int>& B)
        {
            if(A[0] == B[0])
                return A[1] > B[1];
            return A[0] < B[0];
        });

        int Count = 0, MaxEnd = 0;

        for(auto& Interval : intervals)
        {
            if(Interval[1] > MaxEnd)
            {
                Count++;
                MaxEnd = Interval[1];
            }
        }
        return Count;
    }
};