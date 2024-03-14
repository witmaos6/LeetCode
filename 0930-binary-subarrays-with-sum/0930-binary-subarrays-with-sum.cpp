class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        const int N = static_cast<int>(nums.size());
        int Count = 0;
        
        for(int i = 0; i < N; i++)
        {
            int CurrValue = 0;
            for(int j = i; j < N; j++)
            {
                CurrValue += nums[j];
                if(CurrValue == goal)
                {
                    Count++;
                }
                else if(CurrValue > goal)
                {
                    break;
                }
            }
        }
        return Count;
    }
};