class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right)
    {
        const int Mod = 1e9 + 7;
       
        priority_queue<long long, vector<long long>> MaxHeap;
        
        for(int i = 0; i < n; i++)
        {
            long long Sum = 0;
            for(int j = i; j < n; j++)
            {
                Sum = (Sum + nums[j]) % Mod;
                
                MaxHeap.push(Sum);
                if(MaxHeap.size() > right)
                {
                    MaxHeap.pop();
                }
            }
        }
        
        long long SubSum = 0;
        for(int i = 0; i < right - left + 1; i++)
        {
            if(!MaxHeap.empty())
            {
                SubSum = (SubSum + MaxHeap.top()) % Mod;
                MaxHeap.pop();
            }
        }
        
        return static_cast<int>(SubSum);
    }
};