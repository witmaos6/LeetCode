class Solution {
public:
    long long countBadPairs(vector<int>& nums)
    {
        const long long N = static_cast<int>(nums.size());
        long long GoodPairs = 0;
        unordered_map<int, int> Freq;

        for(int i = 0; i < N; i++)
        {
            int Key = nums[i] - i;
            GoodPairs += Freq[Key];
            Freq[Key]++;
        }

        return (N * (N - 1)) / 2 - GoodPairs;
    }
};