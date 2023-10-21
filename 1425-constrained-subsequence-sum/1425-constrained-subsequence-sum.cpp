class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        
        priority_queue<pair<int, int>> MaxHeap;
        MaxHeap.push({nums[0], 0});
        
        vector<int>Memo(N, 0);
        Memo[0] = nums[0];
        
        int Result = nums[0];
        
        for(int i = 1; i < N; i++)
        {
            while(!MaxHeap.empty())
            {
                auto [Value, Index] = MaxHeap.top();
                if(i - Index > k)
                {
                    MaxHeap.pop();
                }
                else
                {
                    break;
                }
            }
            if(!MaxHeap.empty())
            {
                Memo[i] = max(nums[i], nums[i] + MaxHeap.top().first); 
            
                Result = max(Result, Memo[i]);
                MaxHeap.push({Memo[i], i});
            }
        }
        return Result;
    }
};