class Solution {
public:
    int minMoves(vector<int>& nums)
    {
        int Max = *ranges::max_element(nums);
        int Result = 0;
        for(int& Num : nums)
        {
            Result += Max - Num;
        }
        return Result;
    }
};