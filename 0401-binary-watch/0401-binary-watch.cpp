class Solution {
    array<int, 4> Hours = {1, 2, 4, 8};
    array<int, 6> Minutes = {1, 2, 4, 8, 16, 32};
    set<string> Times;
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        if(turnedOn >= 9)
            return {};

        Backtracking(0, 0, turnedOn, 0, 0);
        vector<string> Result;
        Result.reserve(Times.size());
        for(const string& Time : Times)
        {
            Result.push_back(Time);
        }

        return Result;
    }

private:
    void Backtracking(int HIndex, int MIndex, int Count, int Hour, int Minute)
    {
        if(Count == 0)
        {
            string Time = to_string(Hour) + ':';
            if(Minute < 10)
            {
                Time += '0';
            }
            Time += to_string(Minute);
            Times.insert(Time);
            return;
        }

        for(int i = MIndex; i < 6; i++)
        {
            Minute += Minutes[i];
            if(Minute < 60)
            {
                Backtracking(HIndex, i + 1, Count - 1, Hour, Minute);
            }
            Minute -= Minutes[i];
        }
        for(int i = HIndex; i < 4; i++)
        {
            Hour += Hours[i];
            if(Hour < 12)
            {
                Backtracking(i + 1, MIndex, Count - 1, Hour, Minute);
            }
            Hour -= Hours[i];
        }
    }
};