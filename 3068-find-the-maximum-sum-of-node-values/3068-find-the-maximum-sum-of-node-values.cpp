class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges)
    {
        long long Total = accumulate(nums.begin(), nums.end(), 0ll);
        
        long long TotalDiff = 0;
        int PositiveCount = 0;
        long long MinAbsDiff = numeric_limits<int>::max();
        
        for(int Num : nums)
        {
            long long Diff = (Num ^ k) - Num;
            
            if(Diff > 0)
            {
                TotalDiff += Diff;
                PositiveCount++;
            }
            
            MinAbsDiff = min(MinAbsDiff, abs(Diff));
        }
        
        if(PositiveCount % 2 == 1)
        {
            TotalDiff = TotalDiff - MinAbsDiff;
        }
        
        return Total + TotalDiff;
    }
};