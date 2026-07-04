class Solution {
    using Node = pair<int, int>;
public:
    int minScore(int n, vector<vector<int>>& roads)
    {
        vector<vector<Node>> Graph(n + 1);

        for(vector<int>& City : roads)
        {
            Graph[City[0]].push_back({City[1], City[2]});
            Graph[City[1]].push_back({City[0], City[2]});
        }

        vector<bool> Visited(n + 1);
        Visited[1] = true;
        queue<int> BFS;
        BFS.push(1);
        int MinScore = INT_MAX;

        while(!BFS.empty())
        {
            int CurrCity = BFS.front();
            BFS.pop();

            for(auto& [City, Distance] : Graph[CurrCity])
            {
                MinScore = min(MinScore, Distance);
                if(!Visited[City])
                {
                    Visited[City] = true;
                    BFS.push(City);
                }
            }
        }

        return MinScore;
    }
};