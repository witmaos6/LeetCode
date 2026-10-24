class Solution {
    array<int, 12> Month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        int ArriveAlice = DayToInt(arriveAlice);
        int LeaveAlice = DayToInt(leaveAlice);

        int ArriveBob = DayToInt(arriveBob);
        int LeaveBob = DayToInt(leaveBob);

        int Begin = max(ArriveBob, ArriveAlice);
        int End = min(LeaveAlice, LeaveBob);

        return max(0, End - Begin + 1);
    }
private:
    int DayToInt(string& S)
    {
        int Mon = (S[0] - '0') * 10 + (S[1] - '0');
        int Day = (S[3] - '0') * 10 + (S[4] - '0');

        for(int i = 0; i < Mon - 1; i++)
        {
            Day += Month[i];
        }
        return Day;
    }
};