class Solution {
    using Pair = pair<int, int>;
public:
    vector<int> arrayRankTransform(vector<int>& arr)
    {
        if(arr.empty())
        {
            return {};
        }
        
        const int N = static_cast<int>(arr.size());
        priority_queue<Pair, vector<Pair>, greater<Pair>> MaxHeap;
        
        for(int i = 0; i < N; i++)
        {
            MaxHeap.emplace(arr[i], i);
        }
        
        vector<int> Result(N);
        int PrevNum = MaxHeap.top().first;
        int Rank = 1;
        
        while(!MaxHeap.empty())
        {
            auto[Num, Index] = MaxHeap.top();
            MaxHeap.pop();
            
            if(PrevNum != Num)
            {
                Rank++;
            }
            
            PrevNum = Num;
            Result[Index] = Rank;
        }
        
        return Result;
    }
};