class Solution {
    using Pair = pair<int, int>;
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier)
    {
        priority_queue<Pair, vector<Pair>, greater<Pair>> MinHeap;
        const int N = static_cast<int>(nums.size());
        for(int i = 0; i < N; i++)
        {
            MinHeap.emplace(nums[i], i);
        }
        
        for(int i = 0; i < k; i++)
        {
            auto[Num, Index] = MinHeap.top();
            MinHeap.pop();
            
            Num *= multiplier;
            nums[Index] = Num;
            
            MinHeap.emplace(Num, Index);
        }
        
        return nums;
    }
};