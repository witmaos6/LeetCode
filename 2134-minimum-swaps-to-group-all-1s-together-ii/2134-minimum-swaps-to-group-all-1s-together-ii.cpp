class Solution {
public:
    int minSwaps(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int CountOnes = count(nums.begin(), nums.end(), 1);
        int Count = accumulate(nums.begin(), nums.begin() + CountOnes, 0);
        int Max = Count;
        
        for (int i = CountOnes; i < N + CountOnes; ++i)
        {
            Count += nums[i % N] - nums[(i - CountOnes + N) % N];
            Max = max(Max, Count);
        }
        return CountOnes - Max;
    }
};