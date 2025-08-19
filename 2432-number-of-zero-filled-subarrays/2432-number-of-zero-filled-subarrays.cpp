class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        nums.push_back(1);
        long long Count = 0;
        long long Result = 0;
        for(int& Num : nums)
        {
            if(Num == 0)
            {
                Count++;
            }
            else
            {
                Result += (Count * (Count + 1) >> 1);
                Count = 0;
            }
        }
        return Result;
    }
};