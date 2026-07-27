class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        const size_t NrOfNums = 2;
        priority_queue<int, vector<int>, greater<int>> MinHeap;
        for(int& Num : nums)
        {
            MinHeap.push(Num);
            if(MinHeap.size() > NrOfNums)
            {
                MinHeap.pop();
            }
        }

        int Result = 1;
        while(!MinHeap.empty())
        {
            Result *= MinHeap.top() - 1;
            MinHeap.pop();
        }
        return Result;
    }
};