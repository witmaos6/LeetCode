class Solution {
    vector<int> Degree;
    unordered_map<int, vector<int>> Cities;
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads)
    {
        Degree.resize(n);
        
        for(vector<int>& Road : roads)
        {
            Degree[Road[0]]++;
            Degree[Road[1]]++;
            
            Cities[Road[0]].push_back(Road[1]);
            Cities[Road[1]].push_back(Road[0]);
        }
        
        int MaxRank = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int NetworkRank = Degree[i] + Degree[j];
                if(find(Cities[i].begin(), Cities[i].end(), j) != Cities[i].end())
                {
                    NetworkRank--;
                }
                
                MaxRank = max(MaxRank, NetworkRank);
            }
        }
        
        return MaxRank;
    }
};