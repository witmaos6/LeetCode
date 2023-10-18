class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time)
    {
        vector<vector<int>> Graph(n);
        vector<int> Degree(n);
        vector<int> Time(n);
        for(vector<int>& Relation : relations)
        {
            int Require = Relation[0] - 1;
            int Next = Relation[1] - 1;
            Graph[Require].push_back(Next);
            Degree[Next]++;
        }
        
        queue<pair<int, int>> BFS;
        for(int i = 0; i < n; i++)
        {
            if(Degree[i] == 0)
            {
                BFS.push({i, 0});
            }
        }
        
        while(!BFS.empty())
        {
            auto [Node, T] = BFS.front();
            BFS.pop();
            
            int CompleteTime = T + time[Node];
            Time[Node] = CompleteTime;
            
            for(int Next : Graph[Node])
            {
                Time[Next] = max(Time[Next], CompleteTime);
                
                Degree[Next]--;
                if(Degree[Next] == 0)
                {
                    BFS.push({Next, Time[Next]});
                }
            }
        }
        
        return *max_element(Time.begin(), Time.end());
    }
};