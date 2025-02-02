class Solution {
public:
    bool check(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        
        int CountDecrease = 0;
        for(int i = 1; i < N; i++)
        {
            if(nums[i] < nums[i - 1])
            {
                CountDecrease++;
                if(CountDecrease > 1)
                {
                    break;
                }
            }
        }

        return (nums[0] >= nums.back() && CountDecrease == 1) || CountDecrease == 0;
    }
};