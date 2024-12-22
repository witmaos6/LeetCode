class Solution {
    using Pair = pair<int, int>;
    map<Pair, int> Memo;
    int N = 0;
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries)
    {
        N = static_cast<int>(heights.size());
        const int M = static_cast<int>(queries.size());

        vector<int> CanMeet(N);
        stack<int> Monotonic;
        for(int i = N - 1; i >= 0; i--)
        {
            while(!Monotonic.empty() && heights[Monotonic.top()] <= heights[i])
            {
                Monotonic.pop();
            }
            if(Monotonic.empty())
            {
                CanMeet[i] = N;
            }
            else
            {
                CanMeet[i] = Monotonic.top();
            }
            Monotonic.push(i);
        }
        
        vector<int> Result(M);
        for(int i = 0; i < M; i++)
        {
            int A = queries[i][0];
            int B = queries[i][1];
            
            if(A > B)
                swap(A, B);
            
            int A1 = DP(B, A, heights, CanMeet);
            Result[i] = A1;
        }
        return Result;
    }
private:
    int DP(int Index, int Target, const vector<int>& Heights, const vector<int>& CanMeet)
    {
        if(Index == N)
            return -1;
        
        if(Memo.find({Index, Target}) != Memo.end())
            return Memo[{Index, Target}];
        
        if(Index == Target)
            return Index;
        
        if(Index > Target && Heights[Index] > Heights[Target])
            return Memo[{Index, Target}] = Index;
        
        return Memo[{Index, Target}] = DP(CanMeet[Index], Target, Heights, CanMeet);
    }
};