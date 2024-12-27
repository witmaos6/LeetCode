class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values)
    {
        const int N = static_cast<int>(values.size());
        
        int MaxResult = 0;
        int Left = 0;
        
        for(int Right = 1; Right < N; Right++)
        {
            int SightseeingSpot = values[Left] + values[Right] + Left - Right;
            MaxResult = max(MaxResult, SightseeingSpot);
            
            if(values[Left] + Left < values[Right] + Right)
            {
                Left = Right;
            }
        }
        
        return MaxResult;
    }
};