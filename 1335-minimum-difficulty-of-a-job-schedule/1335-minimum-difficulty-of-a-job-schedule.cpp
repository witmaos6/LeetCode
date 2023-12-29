class Solution {
    int N = 0;
    vector<vector<int>> Memo;
public:
    int minDifficulty(vector<int>& jobDifficulty, int d)
    {
        N = static_cast<int>(jobDifficulty.size());
        
        if(N < d)
        {
            return -1;
        }
        
        if(N == d)
        {
            return accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
        }
        
        Memo.resize(N + 1, vector<int>(d + 1, -1));
        
        return DP(jobDifficulty, d, 0);
    }
    
private:
    int DP(vector<int>& Job, int Day, int Index)
    {
        if(Day == 1)
        {
            return *max_element(Job.begin() + Index, Job.end());
        }
     
        if(Memo[Index][Day] != -1)
        {
            return Memo[Index][Day];
        }
        
        int MaxDifficulty = -1;
        int SubSum = INT_MAX;
        
        for(int i = Index; i <= N - Day; i++)
        {
            MaxDifficulty = max(MaxDifficulty, Job[i]);
            int NextSum = DP(Job, Day - 1, i + 1);
            
            SubSum = min(SubSum, MaxDifficulty + NextSum);
        }
        
        Memo[Index][Day] = SubSum;
        return Memo[Index][Day];
    }
};