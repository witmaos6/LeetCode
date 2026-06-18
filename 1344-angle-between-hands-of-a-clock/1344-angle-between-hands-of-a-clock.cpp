class Solution {
public:
    double angleClock(int hour, int minutes)
    {
        double MinuteAngle = minutes * 6;
        double HourAngle = (hour * 30) + (0.5f * minutes);

        double ClockwiseAngle = abs(MinuteAngle - HourAngle);
        double ReverseClockwiseAngle = 360 - ClockwiseAngle;

        return min(ClockwiseAngle, ReverseClockwiseAngle);
    }
};