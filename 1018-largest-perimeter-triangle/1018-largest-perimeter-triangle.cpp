class Solution {
public:
    int largestPerimeter(vector<int>& nums)
    {
        int N = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end(), greater<>());

        for (int i = 0; i < N - 2; i++)
        {
            if(nums[i] < (nums[i+1] + nums[i+2]))
            {
                return (nums[i] + nums[i + 1] + nums[i + 2]);
            }
        }
        return 0;
    }
};