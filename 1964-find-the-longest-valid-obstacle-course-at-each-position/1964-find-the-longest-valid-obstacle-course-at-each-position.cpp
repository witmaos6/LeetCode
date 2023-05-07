class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles)
    {
        size_t N = obstacles.size();
        
        vector<int> Memo(N, 1e9);
        vector<int> Result(N);
        
        for(size_t i = 0; i < N; i++)
        {
            int Index = upper_bound(Memo.begin(), Memo.end(), obstacles[i]) - Memo.begin();
            
            Result[i] = Index + 1;
            
            Memo[Index] = obstacles[i];
        }
        
        return Result;
    }
};