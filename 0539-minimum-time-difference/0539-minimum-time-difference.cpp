class Solution {
public:
    int findMinDifference(vector<string>& timePoints)
    {
        const int N = static_cast<int>(timePoints.size());
        vector<int> Minutes;
        Minutes.reserve(2 * N);
        
        for(string& HM : timePoints)
        {
            int HourToMinuteInt = stoi(HM.substr(0, 2)) * 60;
            int MinuteToInt = stoi(HM.substr(3, 2));
            
            Minutes.push_back(HourToMinuteInt + MinuteToInt);
            
            int HourAdd24 = HourToMinuteInt + 1440;
            Minutes.push_back(HourAdd24 + MinuteToInt);
        }
        
        sort(Minutes.begin(), Minutes.end());
        int MinDiff = INT_MAX;
        
        for(int i = 1; i < 2 * N; i++)
        {
            int Diff = Minutes[i] - Minutes[i - 1];
            MinDiff = min(MinDiff, Diff);
        }
        
        return MinDiff;
    }
};