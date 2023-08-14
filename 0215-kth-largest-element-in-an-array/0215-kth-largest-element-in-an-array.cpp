class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> MinHeap;
        
        for(int Num : nums)
        {
            MinHeap.push(Num);
            
            if(MinHeap.size() > k)
            {
                MinHeap.pop();
            }
        }
        
        return MinHeap.top();
    }
};