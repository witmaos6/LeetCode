class Solution {
    vector<bool> Visited;
    vector<bool> IsSafe;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        const int N = static_cast<int>(graph.size());
        Visited.resize(N);
        IsSafe.resize(N);

        for(int i = 0; i < N; i++)
        {
            DFS(i, graph);
        }
        
        vector<int> SafeNodes;
        for(int i = 0; i < N; i++)
        {
            if(!IsSafe[i])
            {
                SafeNodes.push_back(i);
            }
        }

        return SafeNodes;
    }

private:
    bool DFS(int Node, vector<vector<int>>& Graph)
    {
        if(IsSafe[Node])
        {
            return true;
        }
        if(Visited[Node])
        {
            return false;
        }

        Visited[Node] = true;
        IsSafe[Node] = true;

        for(int& Neighbor : Graph[Node])
        {
            if(DFS(Neighbor, Graph))
            {
                return true;
            }
        }

        IsSafe[Node] = false;
        return false;
    }
};