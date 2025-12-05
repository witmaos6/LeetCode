class Solution {
public:
    int countPartitions(vector<int>& nums)
    {
        int LeftSum = nums.front();
        int RightSum = accumulate(nums.begin() + 1, nums.end(), 0);
        const int N = static_cast<int>(nums.size());
        int Count = ((LeftSum - RightSum) % 2 == 0) ? 1 : 0;

        for(int i = 1; i < N - 1; i++)
        {
            LeftSum += nums[i];
            RightSum -= nums[i];

            if((LeftSum - RightSum) % 2 == 0)
            {
                Count++;
            }
        }
        return Count;
    }
};