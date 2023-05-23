class KthLargest {
    int K = 0;
    priority_queue<int, vector<int>, greater<int>> MinHeap;
public:
    KthLargest(int k, vector<int>& nums)
    {
        K = k;
        
        for(int& Num : nums)
        {
            MinHeap.push(Num);
            if(MinHeap.size() > k)
            {
                MinHeap.pop();
            }
        }
    }
    
    int add(int val)
    {
        MinHeap.push(val);
        if(MinHeap.size() > K)
        {
            MinHeap.pop();
        }

        return MinHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */