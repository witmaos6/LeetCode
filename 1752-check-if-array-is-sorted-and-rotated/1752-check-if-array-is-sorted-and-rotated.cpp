class Solution {
public:
    bool check(vector<int>& nums)
    {
        const int N = nums.size();
        int Count = 0;
        for(int i = 1; i < N; i++)
        {
            if(nums[i - 1] > nums[i])
            {
                Count++;
                if(Count > 1)
                    break;
            }
        }

        return (nums[0] >= nums.back() && Count == 1) || Count == 0;
    }
};