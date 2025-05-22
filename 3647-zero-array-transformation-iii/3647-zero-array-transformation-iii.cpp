class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries)
    {
        const int N = static_cast<int>(nums.size());
        vector<vector<int>> Queries(N);
        for(vector<int>& Query : queries)
        {
            Queries[Query[0]].push_back(Query[1]);
        }

        priority_queue<int> MaxHeap;
        vector<int> Count(N + 1);
        int Decrement = 0;

        int j = 0;
        for(int i = 0; i < N; i++)
        {
            const int Num = nums[i];
            Decrement += Count[i];

            for(int Q : Queries[i])
            {
                MaxHeap.push(Q);
            }

            while (Num > Decrement && MaxHeap.size() > 0 && MaxHeap.top() >= i)
            {
                Count[MaxHeap.top() + 1]--;
                Decrement++;
                MaxHeap.pop();
            }
            if(Num > Decrement)
                return -1;
        }

        return MaxHeap.size();
    }
};