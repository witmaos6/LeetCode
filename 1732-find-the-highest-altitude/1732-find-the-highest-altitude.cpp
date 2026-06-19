class Solution {
public:
    int largestAltitude(vector<int>& gain)
    {
        int PrefixSum = 0;
        int Max = 0;

        for(int& Num : gain)
        {
            PrefixSum += Num;
            Max = max(Max, PrefixSum);
        }
        return Max;
    }
};