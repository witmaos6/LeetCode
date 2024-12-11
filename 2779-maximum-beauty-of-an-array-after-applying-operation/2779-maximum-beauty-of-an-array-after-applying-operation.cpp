class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        const int N = static_cast<int>(nums.size());
        const int Range = 2 * k;
        int Right = 0;
        int Result = 0;
        
        for(int i = 0; i < N; i++)
        {
            while(nums[i] - nums[Right] > Range)
            {
                Right++;
            }
            
            Result = max(Result, i - Right + 1);
        }
        
        return Result;
    }
};