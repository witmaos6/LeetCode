class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> MinHeap;
        
        for(int i = 0; i < k; i++)
        {
            MinHeap.push(nums[i]);
        }
        
        int N = static_cast<int>(nums.size());
        
        for(int i = k; i < N; i++)
        {
            if(MinHeap.top() <= nums[i])
            {
                MinHeap.pop();
                MinHeap.push(nums[i]);
            }
        }
        
        return MinHeap.top();
    }
};