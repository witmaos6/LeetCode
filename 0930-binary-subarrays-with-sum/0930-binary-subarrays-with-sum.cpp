class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        const int N = static_cast<int>(nums.size());
        int Left = 0;
        int Count = 0;
        int TotalCount = 0;
        
        for(int Right = 0; Right < N; Right++)
        {
            if(nums[Right] == 1)
            {
                goal--;
                Count = 0;
            }
            
            while(goal == 0 && Left <= Right)
            {
                goal += nums[Left];
                Left++;
                Count++;
                if(Left > Right - goal + 1)
                {
                    break;
                }
            }
            
            while(goal < 0)
            {
                goal += nums[Left];
                Left++;
            }
            
            TotalCount += Count;
        }
        
        return TotalCount;
    }
};