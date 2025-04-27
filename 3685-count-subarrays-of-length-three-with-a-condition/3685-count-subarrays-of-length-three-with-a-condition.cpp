class Solution {
public:
    int countSubarrays(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int Count = 0;
        for(int i = 0; i < N - 2; i++)
        {
            int Sum = nums[i] + nums[i + 2];
            if(Sum * 2 == nums[i + 1])
            {
                Count++;
            }
        }
        return Count;
    }
};