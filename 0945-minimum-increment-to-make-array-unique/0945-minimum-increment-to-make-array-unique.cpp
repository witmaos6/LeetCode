class Solution {
public:
    int minIncrementForUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        
        const int N = static_cast<int>(nums.size());
        int Count = 0;
        
        for(int i = 1; i < N; i++)
        {
            if(nums[i - 1] >= nums[i])
            {
                int Temp = nums[i - 1] + 1;
                Count += Temp - nums[i];
                nums[i] = Temp;
            }
        }
        
        return Count;
    }
};