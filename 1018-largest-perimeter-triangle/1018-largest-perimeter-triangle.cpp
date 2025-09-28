class Solution {
public:
    int largestPerimeter(vector<int>& nums)
    {
        int N = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end(), greater<>());
        int MaxPerimeter = 0;

        for (int i = 0; i < N - 2; i++)
        {
            if(nums[i] < (nums[i+1] + nums[i+2]))
            {
                MaxPerimeter = (nums[i] + nums[i + 1] + nums[i + 2]);
                break;
            }
        }
        return MaxPerimeter;
    }
};