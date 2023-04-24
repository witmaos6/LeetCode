class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> MaxHeap;

        for(int& stone : stones)
        {
            MaxHeap.push(stone);
        }

        while(MaxHeap.size() > 1)
        {
            int Stone1 = MaxHeap.top();
            MaxHeap.pop();
            int Stone2 = MaxHeap.top();
            MaxHeap.pop();
            
            Stone1 -= Stone2;
            if(Stone1 > 0)
            {
                MaxHeap.push(Stone1);
            }
        }
        
        if(MaxHeap.empty())
        {
            return 0;
        }
        return MaxHeap.top();
    }
};