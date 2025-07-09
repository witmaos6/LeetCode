class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime)
    {
        const int N = static_cast<int>(startTime.size());
        vector<int> Gaps;
        Gaps.reserve(N + 1);
        Gaps.push_back(startTime[0]);

        for(int i = 1; i < N; i++)
        {
            Gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        Gaps.push_back(eventTime - endTime[N - 1]);

        int Size = min(k + 1, static_cast<int>(Gaps.size()));
        long long Curr = 0, Best = 0;
        for(int i = 0; i < Size; i++)
        {
            Curr += Gaps[i];
        }
        Best = Curr;
        int GapsSize = static_cast<int>(Gaps.size());
        for(int i = Size; i < GapsSize; i++)
        {
            Curr += Gaps[i] - Gaps[i - Size];
            Best = max(Best, Curr);
        }
        return static_cast<int>(Best);
    }
};