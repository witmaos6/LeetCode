class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        target = abs(target);
        int Total = accumulate(nums.begin(), nums.end(), 0);
        if(target > Total || (Total - target) & 1)
            return 0;
        
        int ReqSum = (Total - target) / 2;
        vector<int> Memo(ReqSum + 1, 0);
        Memo[0] = 1;
        
        for(int& Num : nums)
        {
            for(int i = ReqSum; i >= Num; i--)
            {
                Memo[i] += Memo[i - Num];
            }
        }
        
        return Memo[ReqSum];
    }
};