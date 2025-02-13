class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> MinHeap;
        for(int& Num : nums)
        {
            MinHeap.push(Num);
        }

        if(MinHeap.top() >= k)
        {
            return 0;
        }

        int CountOper = 0;
        while(MinHeap.size() >= 2)
        {
            long long X = MinHeap.top();
            MinHeap.pop();
            long long Y = MinHeap.top();
            MinHeap.pop();

            long long NewNum = min(X, Y) * 2 + max(X, Y);
            MinHeap.push(NewNum);
            CountOper++;

            if(MinHeap.top() >= k)
            {
                break;
            }
        }

        return CountOper;
    }
};