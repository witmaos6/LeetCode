class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings)
    {
        sort(meetings.begin(), meetings.end());
        const int N = static_cast<int>(meetings.size());
        int i = 0;
        for(int i = 0; i < N; i++)
        {
            int Begin = meetings[i][0];
            int End = meetings[i][1];
            
            while(i + 1 < N && End >= meetings[i + 1][0])
            {
                End = max(End, meetings[i + 1][1]);
                i++;
            }

            days -= (End - Begin) + 1;
        }

        return days;
    }
};