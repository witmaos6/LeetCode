class Solution {
    int N = 0;
public:
    bool validPartition(vector<int>& nums)
    {
        N = static_cast<int>(nums.size());
        
        vector<int> Memo = {true, false, nums[0] == nums[1]};
        
        for(int i = 2; i < N; i++)
        {
            bool Valid = false;
            
            if(nums[i] == nums[i - 1] && Memo[1])
            {
                Valid = true;
            }
            else if(nums[i] == nums[i - 1] && nums[i] == nums[i - 2] && Memo[0])
            {
                Valid = true;
            }
            else if(nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1 && Memo[0])
            {
                Valid = true;
            }
            
            Memo[0] = Memo[1];
            Memo[1] = Memo[2];
            Memo[2] = Valid;
        }
        
        return Memo[2];
    }
};