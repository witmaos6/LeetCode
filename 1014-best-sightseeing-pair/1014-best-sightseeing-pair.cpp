class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values)
    {
        const int N = static_cast<int>(values.size());
        
        int MaxResult = 0;
        int MaxLeft = values[0];
        
        for(int i = 1; i < N; i++)
        {
            MaxResult = max(MaxResult, MaxLeft + values[i] - i);
            MaxLeft = max(MaxLeft, values[i] + i);
        }
        
        return MaxResult;
    }
};