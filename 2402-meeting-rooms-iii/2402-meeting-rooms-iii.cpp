class Solution {
    using Pair = pair<long long, int>;
public:
    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        vector<int> Rooms(n);
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> AvailRooms;
        priority_queue<Pair, vector<Pair>, greater<Pair>> Time;
        for(int i = 0; i < n; i++)
        {
            AvailRooms.push(i);
        }
        const int M = static_cast<int>(meetings.size());
        for(int i = 0; i < M; i++)
        {
            while(!Time.empty() && Time.top().first <= meetings[i][0])
            {
                AvailRooms.push(Time.top().second);
                Time.pop();
            }
            if(!AvailRooms.empty())
            {
                int Index = AvailRooms.top();
                AvailRooms.pop();
                Rooms[Index]++;
                Time.emplace(meetings[i][1], Index);
            }
            else
            {
                auto [EndTime, Index] = Time.top();
                Time.pop();
                Rooms[Index]++;
                Time.emplace(EndTime + meetings[i][1] - meetings[i][0], Index);
            }
        }
        int MaxBooking = -1;
        int MostRoomIndex = -1;
        for(int i = 0; i < n; i++)
        {
            if(Rooms[i] > MaxBooking)
            {
                MaxBooking = Rooms[i];
                MostRoomIndex = i;
            }
        }
        return MostRoomIndex;
    }
};