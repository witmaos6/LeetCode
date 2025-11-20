class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [&](auto &A, auto &B){
            if(A[1] == B[1])
                return A[0] > B[0];
            return A[1] < B[1];
        });

        int Result = 0;
        int A = -1, B = -1;

        for(vector<int>& Interval : intervals)
        {
            int L = Interval[0];
            int R = Interval[1];

            if(L > B)
            {
                A = R - 1;
                B = R;
                Result += 2;
            }
            else if(L > A)
            {
                A = B;
                B = R;
                Result +=1;
            }
        }
        return Result;
    }
};