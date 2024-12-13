class Solution {
    using Pair = pair<int, int>;
public:
    long long findScore(vector<int>& nums)
    {
        priority_queue<Pair, vector<Pair>, greater<Pair>> MinHeap;
        const int N = static_cast<int>(nums.size());
        
        for(int i = 0; i < N; i++)
        {
            MinHeap.emplace(nums[i], i);
        }
        
        unordered_set<int> Marked;
        long long Score = 0;
        
        while(!MinHeap.empty())
        {
            auto[Num, Index] = MinHeap.top();
            MinHeap.pop();
            
            if(Marked.find(Index) != Marked.end())
                continue;
            
            Score += Num;
            Marked.insert(Index);
            Marked.insert(Index - 1);
            Marked.insert(Index + 1);
        }
        
        return Score;
    }
};