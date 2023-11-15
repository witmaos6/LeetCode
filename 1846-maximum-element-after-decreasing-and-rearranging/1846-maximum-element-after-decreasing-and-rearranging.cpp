class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr)
    {
        priority_queue<int, vector<int>, greater<>> MinHeap;
        
        for(int Num : arr)
        {
            MinHeap.push(Num);
        }
        
        int Prev = 0;
        
        while(!MinHeap.empty())
        {
            int Num = MinHeap.top();
            MinHeap.pop();
            
            if(Num - Prev >= 2)
            {
                Prev = Prev + 1;
            }
            else
            {
                Prev = Num;
            }
        }
        
        return Prev;
    }
};