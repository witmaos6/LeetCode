class Solution {
public:
    int countPartitions(vector<int>& nums)
    {
        int LeftSum = 0;
        int RightSum = accumulate(nums.begin(), nums.end(), 0);
        const int N = static_cast<int>(nums.size());
        int Count = 0;

        for(int i = 0; i < N - 1; i++)
        {
            LeftSum += nums[i];
            RightSum -= nums[i];

            if(((LeftSum - RightSum) & 1) == 0)
            {
                Count++;
            }
        }
        return Count;
    }
};