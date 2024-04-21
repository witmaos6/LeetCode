class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        if(source == destination)
            return true;
        
        unordered_map<int, vector<int>> Graph;
        for(vector<int>& Edge : edges)
        {
            Graph[Edge[0]].push_back(Edge[1]);
            Graph[Edge[1]].push_back(Edge[0]);
        }
        
        vector<bool> Visited(n);
        queue<int> BFS;
        BFS.push(source);
        while(!BFS.empty())
        {
            int CurrNode = BFS.front();
            BFS.pop();
            if(Visited[CurrNode])
            {
                continue;
            }
            Visited[CurrNode] = true;
            
            for(int NextNode : Graph[CurrNode])
            {
                if(NextNode == destination)
                    return true;

                BFS.push(NextNode);
            }
        }
        return false;
    }
};