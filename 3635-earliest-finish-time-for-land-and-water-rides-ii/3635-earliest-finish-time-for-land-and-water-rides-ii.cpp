class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration)
    {
        int MinL = INT_MAX, MinW = MinL, Result = MinW;
        const int N = landStartTime.size();
        const int M = waterStartTime.size();

        for(int i = 0; i < N; i++)
        {
            MinL = min(MinL, landStartTime[i] + landDuration[i]);
        }
        for(int i = 0; i < M; i++)
        {
            MinW = min(MinW, waterStartTime[i] + waterDuration[i]);
            Result = min(Result, max(MinL, waterStartTime[i]) + waterDuration[i]);
        }
        for(int i = 0; i < N; i++)
        {
            Result = min(Result, max(MinW, landStartTime[i]) + landDuration[i]);
        }
        return Result;
    }
};