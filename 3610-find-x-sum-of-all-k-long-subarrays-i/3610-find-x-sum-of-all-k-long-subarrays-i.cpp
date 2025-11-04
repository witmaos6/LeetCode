class Solution {
    using Pair = pair<int, int>;
public:
    vector<int> findXSum(vector<int>& nums, int k, int x)
    {
        const int N = static_cast<int>(nums.size());

        vector<int> Freq(51);
        for(int i = 0; i < k; i++)
        {
            Freq[nums[i]]++;
        }

        priority_queue<Pair, vector<Pair>> Heap;
        for(int i = 0; i <= 50; i++)
        {
            if(Freq[i] > 0)
            {
                Heap.emplace(Freq[i], i);
            }
        }

        int Sum = 0;
        for(int i = 0; i < x && !Heap.empty(); i++)
        {
            Sum += Heap.top().first * Heap.top().second;
            Heap.pop();
        }

        vector<int> Result;
        Result.reserve(N - k + 1);
        Result.push_back(Sum);

        for(int i = 1; i <= N - k; i++)
        {
            Freq[nums[i - 1]]--;
            Freq[nums[k + i - 1]]++;

            priority_queue<Pair> MaxHeap;
            for(int i = 0; i <= 50; i++)
            {
                if(Freq[i] > 0)
                {
                    MaxHeap.emplace(Freq[i], i);
                }
            }

            int CurrSum = 0;
            for(int i = 0; i < x && !MaxHeap.empty(); i++)
            {
                CurrSum += MaxHeap.top().first * MaxHeap.top().second;
                MaxHeap.pop();
            }
            Result.push_back(CurrSum);
        }
        
        return Result;
    }
};