class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums)
    {
        int MinSum = 0;
        int MaxSum = 0;
        for(int& Num : nums)
        {
            MaxSum = max(0, MaxSum + Num);
            MinSum = min(0, MinSum + Num);
        }
        return MaxSum - MinSum;
    }
};