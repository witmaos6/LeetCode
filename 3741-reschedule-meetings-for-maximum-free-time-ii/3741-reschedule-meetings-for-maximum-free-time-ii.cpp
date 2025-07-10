class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime)
    {
        int n = startTime.size();
        int maxLeftGap = startTime[0];               // Free time before first meeting
        int maxRightGap = eventTime - endTime[n - 1];   // Free time after last meeting
        int ans = max(
            maxLeftGap + startTime[1] - endTime[0],        // Merge first gap
            maxRightGap + startTime[n - 1] - endTime[n - 2] // Merge last gap
        );

        for (int i = 1, j = n - 2; i < n && j >= 0; i++, j--) {
            int a = (i == n - 1 ? eventTime : startTime[i + 1]) - endTime[i - 1];
            int b = (endTime[i] - startTime[i] <= maxLeftGap) ? 0 : (endTime[i] - startTime[i]);
            ans = max(ans, a - b);

            int c = startTime[j + 1] - (j == 0 ? 0 : endTime[j - 1]);
            int d = (endTime[j] - startTime[j] <= maxRightGap) ? 0 : (endTime[j] - startTime[j]);
            ans = max(ans, c - d);

            maxLeftGap = max(maxLeftGap, startTime[i] - endTime[i - 1]);
            maxRightGap = max(maxRightGap, startTime[j + 1] - endTime[j]);
        }
        return ans;
    }
};