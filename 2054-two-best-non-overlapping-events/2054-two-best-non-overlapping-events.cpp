class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events)
    {
        sort(events.begin(), events.end());

        const int N = static_cast<int>(events.size());

        vector<int> Start(N);
        vector<int> Sufmax(N + 1);
        for(int i = N - 1; i >= 0; i--)
        {
            Start[i] = events[i][0];
            Sufmax[i] = max(Sufmax[i + 1], events[i][2]);
        }

        int Result = 0;
        for(int i = 0; i < N; i++)
        {
            int j = lower_bound(Start.begin(), Start.end(), events[i][1] + 1) - Start.begin();
            int Memo = events[i][2] + Sufmax[j];
            Result = max(Result, Memo);
        }

        return Result;
    }
};