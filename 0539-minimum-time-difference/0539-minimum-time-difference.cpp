class Solution {
public:
    int findMinDifference(vector<string>& timePoints)
    {
        const int N = static_cast<int>(timePoints.size());
        vector<int> Minutes;
        Minutes.reserve(N);
        
        for(string& HM : timePoints)
        {
            int HourToMinuteInt = stoi(HM.substr(0, 2)) * 60;
            int MinuteToInt = stoi(HM.substr(3, 2));
            
            Minutes.push_back(HourToMinuteInt + MinuteToInt);
        }
        
        sort(Minutes.begin(), Minutes.end());
        int MinDiff = InitMinDiff(Minutes.front(), Minutes.back());
        
        for(int i = 1; i < N; i++)
        {
            int Diff = Minutes[i] - Minutes[i - 1];
            MinDiff = min(MinDiff, Diff);
        }
        
        return MinDiff;
    }
    
private:
    int InitMinDiff(int MinMinute, int MaxMinute)
    {
        int Temp = MinMinute + 1440;
        return Temp - MaxMinute;
    }
};