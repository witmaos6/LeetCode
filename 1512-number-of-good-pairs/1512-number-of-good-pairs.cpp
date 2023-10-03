class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        int N = static_cast<int>(nums.size());
        int Count = 0;
        
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                if(nums[i] == nums[j])
                {
                    Count++;
                }
            }
        }
        
        return Count;
    }
};