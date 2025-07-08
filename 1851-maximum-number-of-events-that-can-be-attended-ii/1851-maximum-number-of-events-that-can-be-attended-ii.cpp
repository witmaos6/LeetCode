class Solution {
    int N = 0;
    vector<vector<int>> Memo;
public:
    int maxValue(vector<vector<int>>& events, int k)
    {
        sort(events.begin(), events.end());
        N = static_cast<int>(events.size());
        Memo.resize(k + 1, vector<int>(N + 1, -1));
        return DP(events, k, 0);
    }

    int DP(vector<vector<int>>& events, int k, int i)
    {
        if(i >= N || k == 0)
            return 0;

        if(Memo[k][i] != -1)
            return Memo[k][i];
        
        int Take = INT_MIN;
        int Skip = INT_MIN;
        int Begin = events[i][0];
        int End = events[i][1];
        int Value = events[i][2];

        Skip = DP(events, k, i + 1);
        Take = Value;
        int j = 0;
        for(j = i + 1; j < N; j++)
        {
            if(events[j][0] > End)
                break;
        }

        Take += DP(events, k - 1, j);

        return Memo[k][i] = max(Take, Skip);
    }
};