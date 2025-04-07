class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int TotalSum = accumulate(nums.begin(), nums.end(), 0);
        if((TotalSum & 1) == 1)
            return false;
        
        int TargetSum = TotalSum / 2;
        vector<bool> Memo(TargetSum + 1, false);
        Memo[0] = true;
        for(const int& Num : nums)
        {
            for(int CurrSum = TargetSum; CurrSum >= Num; CurrSum--)
            {
                Memo[CurrSum] = Memo[CurrSum] || Memo[CurrSum - Num];
                if(Memo[TargetSum])
                    return true;
            }
        }
        return Memo[TargetSum];
    }
};