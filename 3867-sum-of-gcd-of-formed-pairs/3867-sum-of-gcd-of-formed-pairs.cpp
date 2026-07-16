class Solution {
public:
    long long gcdSum(vector<int>& nums)
    {
        int Max = 0;
        for(int& Num : nums)
        {
            Max = max(Max, Num);
            Num = gcd(Num, Max);
        }

        sort(nums.begin(), nums.end());

        long long Result = 0;
        for(int i = 0, j = nums.size() - 1; i < j; i++, j--)
        {
            Result += gcd(nums[i], nums[j]);
        }

        return Result;
    }
};