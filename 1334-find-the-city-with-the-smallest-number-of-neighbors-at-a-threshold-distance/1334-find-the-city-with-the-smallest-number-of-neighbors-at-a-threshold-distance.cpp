class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<int>> Graph(n, vector<int>(n, numeric_limits<int>::max()));
        
        for (int i = 0; i < n; i++)
        {
            Graph[i][i] = 0;
        }
        
        for (const vector<int>& Edge : edges)
        {
            int U = Edge[0];
            int V = Edge[1];
            int Weight = Edge[2];
            
            Graph[U][V] = Weight;
            Graph[V][U] = Weight;
        }
        
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (Graph[i][k] != numeric_limits<int>::max()
                        && Graph[k][j] != numeric_limits<int>::max())
                    {
                        Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
                    }
                }
            }
        }
        
        int MinReachableCities = numeric_limits<int>::max();
        int Result = -1;
        
        for (int i = 0; i < n; i++)
        {
            int ReachableCities = 0;
            for (int j = 0; j < n; j++)
            {
                if (Graph[i][j] <= distanceThreshold)
                {
                    ReachableCities++;
                }
            }
            
            if (ReachableCities <= MinReachableCities)
            {
                MinReachableCities = ReachableCities;
                Result = i;
            }
        }
        
        return Result;
    }
};