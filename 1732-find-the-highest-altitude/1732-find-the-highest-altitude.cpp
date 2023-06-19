class Solution {
public:
    int largestAltitude(vector<int>& gain)
    {
        int MaxAltitude = 0;
        int PrefixSum = 0;
        
        for(int& Num : gain)
        {
            PrefixSum += Num;
            MaxAltitude = max(MaxAltitude, PrefixSum);
        }
        
        return MaxAltitude;
    }
};