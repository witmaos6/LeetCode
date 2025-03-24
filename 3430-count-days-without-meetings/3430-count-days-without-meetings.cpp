class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings)
    {
        sort(meetings.begin(), meetings.end());
        const int N = static_cast<int>(meetings.size());
        int MeetingDays = 0;
        int i = 0;
        while(i < N)
        {
            int Begin = meetings[i][0];
            int End = meetings[i][1];
            
            while(i + 1 < N && End >= meetings[i + 1][0])
            {
                End = max(End, meetings[i + 1][1]);
                i++;
            }

            MeetingDays += (End - Begin) + 1;
            i++;
        }

        return days - MeetingDays;
    }
};