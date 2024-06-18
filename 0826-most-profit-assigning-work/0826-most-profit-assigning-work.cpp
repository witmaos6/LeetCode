class Solution {
    using Job = pair<int, int>;
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        const int N = static_cast<int>(difficulty.size());
        priority_queue<Job, vector<Job>> Jobs;
        for(int i = 0; i < N; i++)
        {
            Jobs.push({profit[i], difficulty[i]});
        }
        
        sort(worker.begin(), worker.end(), greater<>());
        
        int TotalProfits = 0;
        for(int Work : worker)
        {
            while(!Jobs.empty() && Work < Jobs.top().second)
            {
                Jobs.pop();
            }
            if(!Jobs.empty() && Work >= Jobs.top().second)
            {
                TotalProfits += Jobs.top().first;
            }
        }
        
        return TotalProfits;
    }
};