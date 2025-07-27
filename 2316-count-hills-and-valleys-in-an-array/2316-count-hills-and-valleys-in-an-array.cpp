class Solution {
public:
    int countHillValley(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int Count = 0;
        
        for(int i = 1; i < N - 1; i++)
        {
            int j = i + 1;
            while(j < N - 1 && nums[i] == nums[j])
            {
                j++;
            }
            j -= 1;

            if(nums[i - 1] > nums[i] && nums[j + 1] > nums[i])
            {
                Count++;
            }
            else if(nums[i - 1] < nums[i] && nums[j + 1] < nums[j])
            {
                Count++;
            }
            i = j;
        }
        return Count;
    }
};