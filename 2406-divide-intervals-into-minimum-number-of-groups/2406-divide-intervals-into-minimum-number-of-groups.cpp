class Solution {
public:
    int minGroups(vector<vector<int>>& intervals)
    {
        vector<int> StartTimes;
        vector<int> EndTimes;

        for (const vector<int>& Interval : intervals)
        {
            StartTimes.push_back(Interval[0]);
            EndTimes.push_back(Interval[1]);
        }

        sort(StartTimes.begin(), StartTimes.end());
        sort(EndTimes.begin(), EndTimes.end());

        int EndPtr = 0;
        int GroupCount = 0;

        for (int Start : StartTimes)
        {
            if (Start > EndTimes[EndPtr])
            {
                EndPtr++;
            }
            else
            {
                GroupCount++;
            }
        }

        return GroupCount;
    }
};