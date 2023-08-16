class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        
        deque<int> IndexMemo;
        vector<int> Result;
        
        for(int i = 0; i < N; i++)
        {
            while(!IndexMemo.empty() && nums[i] >= nums[IndexMemo.back()])
            {
                IndexMemo.pop_back();
            }
            IndexMemo.push_back(i);
            
            if(IndexMemo.front() <= i - k)
            {
                IndexMemo.pop_front();
            }
            
            if(i >= k - 1)
            {
                Result.push_back(nums[IndexMemo.front()]);
            }
        }
        
        return Result;
    }
};