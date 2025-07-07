class Solution {
public:
    int maxEvents(vector<vector<int>>& events)
    {
        const int N = static_cast<int>(events.size());
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> MinHeap;

        int MaxEvents = 0;
        int i = 0;
        for(int day = 1; i < N || !MinHeap.empty(); day++)
        {
            if(MinHeap.empty())
            {
                day = events[i][0];
            }

            while(i < N && events[i][0] <= day)
            {
                MinHeap.push(events[i][1]);
                i++;
            }

            while(!MinHeap.empty() && MinHeap.top() < day)
            {
                MinHeap.pop();
            }

            if(!MinHeap.empty())
            {
                MinHeap.pop();
                MaxEvents++;
            }
        }
        return MaxEvents;
    }
};