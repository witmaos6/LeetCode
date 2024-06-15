class Solution {
    using Project = pair<int, int>;
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        const int N = static_cast<int>(profits.size());
        
        priority_queue<int, vector<int>> MaxHeap;
        priority_queue<Project, vector<Project>, greater<Project>> MinHeap;
        for(int i = 0; i < N; i++)
        {
            if(capital[i] <= w)
            {
                MaxHeap.push(profits[i]);
            }
            else
            {
                MinHeap.push({capital[i], profits[i]});
            }
        }
        
        int TotalProfits = w;
        for(int i = 0; i < k; i++)
        {
            if(MaxHeap.empty() && MinHeap.empty())
                break;
            
            while(!MinHeap.empty() && MinHeap.top().first <= TotalProfits)
            {
                MaxHeap.push(MinHeap.top().second);
                MinHeap.pop();
            }
            
            if(!MaxHeap.empty())
            {
                TotalProfits += MaxHeap.top();
                MaxHeap.pop();
            }
        }
        
        return TotalProfits;
    }
};