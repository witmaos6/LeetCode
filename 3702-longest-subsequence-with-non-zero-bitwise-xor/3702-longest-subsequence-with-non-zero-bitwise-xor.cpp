class Solution {
public:
    int longestSubsequence(vector<int>& nums)
    {
        int Total = 0;
        bool NonZero = false;

        for(int& Num : nums)
        {
            NonZero |= Num > 0;
            Total ^= Num;
        }

        return NonZero * (nums.size() - (Total == 0));
    }
};