class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK)
    {
        const int N = static_cast<int>(nums.size());
        long long Count = 0;
        int Start = -1, Mini = -1, Maxi = -1;

        for(int i = 0; i < N; i++)
        {
            if(nums[i] < minK || nums[i] > maxK)
            {
                Start = i;
            }
            if(nums[i] == maxK)
            {
                Maxi = i;
            }
            if(nums[i] == minK)
            {
                Mini = i;
            }
            long Temp = min(Mini, Maxi) - Start;
            long SubCount = max(0L, Temp);
            Count += SubCount;
        }
        return Count;
    }
};