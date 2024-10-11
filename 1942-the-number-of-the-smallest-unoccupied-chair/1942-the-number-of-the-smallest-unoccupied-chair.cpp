class Solution {
    using Seat = pair<int, int>;
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend)
    {
        const int N = static_cast<int>(times.size());
        vector<int> Order(N);
        for(int i = 0; i < N; ++i)
        {
            Order[i] = i;
        }
        
        sort(Order.begin(), Order.end(), [&times](int A, int B){
            return times[A][0] < times[B][0];
        });
        
        priority_queue<int, vector<int>, greater<int>> EmptySeat;
        for(int i = 0; i < N; ++i)
        {
            EmptySeat.push(i);
        }
        
        priority_queue<Seat, vector<Seat>, greater<Seat>> TakenSeat;
        for(int Index : Order)
        {
            int Arrival = times[Index][0];
            int Leave = times[Index][1];
            
            while(!TakenSeat.empty() && TakenSeat.top().first <= Arrival)
            {
                EmptySeat.push(TakenSeat.top().second);
                TakenSeat.pop();
            }
            
            int Seat = EmptySeat.top();
            EmptySeat.pop();
            
            if(Index == targetFriend)
            {
                return Seat;
            }
            
            TakenSeat.emplace(Leave, Seat);
        }
        
        return -1;
    }
};