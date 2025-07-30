class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int MaxBitwiseAnd = *max_element(nums.begin(),nums.end());
        int MaxCount = 1;
        int Count = 0;
        int Index = 0;
        
        while(Index < N)
        {
            if(nums[Index] == MaxBitwiseAnd)
            {
                while(Index < N && nums[Index++] == MaxBitwiseAnd)
                {
                    Count++;
                }
                MaxCount = max(MaxCount, Count);
                Count = 0;
            }
            else
            {
                Index++;
            }
        }
        
        return MaxCount;
    }
};