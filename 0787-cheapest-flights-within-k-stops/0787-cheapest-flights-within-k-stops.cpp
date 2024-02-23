class Solution {
    using To = pair<int, int>;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        unordered_map<int, vector<To>> Graph;
        for(vector<int>& Flight : flights)
        {
            Graph[Flight[0]].push_back({Flight[1], Flight[2]});
        }
        
        vector<int> Distance(n + 1, INT_MAX);
        queue<To> DFS;
        DFS.push({src, 0});
        Distance[src] = 0;
        
        while(!DFS.empty() && k >= 0)
        {
            size_t Range = DFS.size();
            
            for(size_t i = 0; i < Range; i++)
            {
                int From = DFS.front().first;
                int CurrCost = DFS.front().second;
                DFS.pop();
                
                for(auto& [To, Cost] : Graph[From])
                {
                    int NextCost = CurrCost + Cost;
                    if(Distance[To] > NextCost)
                    {
                        Distance[To] = NextCost;
                        DFS.push({To, Distance[To]});
                    }
                }
            }
            k--;
        }
        
        return (Distance[dst] == INT_MAX) ? -1 : Distance[dst];
    }
};