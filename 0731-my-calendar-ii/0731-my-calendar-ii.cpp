class MyCalendarTwo {
    map<int, int> EventCount;
public:    
    MyCalendarTwo() {}

    bool book(int start, int end)
    {
        EventCount[start]++;
        EventCount[end]--;

        int Event = 0;
        for (auto &[Time, Change] : EventCount)
        {
            Event += Change;
            if (Event >= 3)
            {
                EventCount[start]--;
                EventCount[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */