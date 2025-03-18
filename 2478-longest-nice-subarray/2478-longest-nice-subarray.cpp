class Solution {
public:
    int longestNiceSubarray(vector<int>& nums)
    {
        int N = static_cast<int>(nums.size());

        int LongestNice = 0;
        int j = 0;
        int num = 0;

        for(int i = 0; i < N; i++)
        {
            while((num & nums[i]) != 0)
            {
                num ^= nums[j];
                j++;
            }

            num |= nums[i];

            LongestNice = max(LongestNice, i - j + 1);
        }

        return LongestNice;
    }
};