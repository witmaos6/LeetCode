class Solution {
public:
    int largestPerimeter(vector<int>& nums)
    {
            int TraverseLength = static_cast<int>(nums.size()) - 2;
        sort(nums.begin(), nums.end(), greater<>());
        int MaxPerimeter = 0;

        for (int i = 0; i < TraverseLength; i++)
        {
            if(nums[i] < (nums[i+1] + nums[i+2]))
            {
                MaxPerimeter += (nums[i] + nums[i + 1] + nums[i + 2]);
                break;
            }
        }
        return MaxPerimeter;
    }
};