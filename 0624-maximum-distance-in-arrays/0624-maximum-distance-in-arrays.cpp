class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        const int N = static_cast<int>(arrays.size());
        int MinInt = arrays[0].front();
        int MaxInt = arrays[0].back();
        int MaxDistance = 0;
        
        for(int i = 1; i < N; i++)
        {
            MaxDistance = max(MaxDistance, abs(arrays[i].back() - MinInt));
            MaxDistance = max(MaxDistance, abs(MaxInt - arrays[i].front()));
            
            MinInt = min(MinInt, arrays[i].front());
            MaxInt = max(MaxInt, arrays[i].back());
        }
        
        return MaxDistance;
    }
};