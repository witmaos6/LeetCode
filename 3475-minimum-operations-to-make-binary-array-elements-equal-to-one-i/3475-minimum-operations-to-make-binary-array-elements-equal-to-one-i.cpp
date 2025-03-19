class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int Count = 0;

        for(int i = 0; i < N - 2; i++)
        {
            if(nums[i] == 0)
            {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                Count++;
            }
        }

        return (nums[N - 2] == 1 && nums[N - 1] == 1) ? Count : -1;
    }
};