class Solution {
    unordered_map<int, vector<int>> Graph;
    int NrOfNodes = 0;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    { 
        for(vector<int>& Edge : edges)
        {
            Graph[Edge[0]].push_back(Edge[1]);
            Graph[Edge[1]].push_back(Edge[0]);
            NrOfNodes = max(NrOfNodes, max(Edge[0], Edge[1]));
        }

        const int N = static_cast<int>(edges.size());
        for(int i = N - 1; i >= 0; i--)
        {
            if(IsTreeIfRemoveEdge(edges[i]))
            {
                return edges[i];
            }
        }
        return edges[0];
    }
private:
    using Pair = pair<int, int>;
    bool IsTreeIfRemoveEdge(const vector<int>& Edge)
    {
        vector<bool> Visited(NrOfNodes);
        Visited[0] = true;

        queue<Pair> BFS;
        BFS.push({1, 0});

        while(!BFS.empty())
        {
            auto [Node, Parent] = BFS.front();
            BFS.pop();
            
            if(Visited[Node])
            {
                return false;
            }
            Visited[Node] = true;

            for(int& Adj : Graph[Node])
            {
                if((Node == Edge[0] && Adj == Edge[1]) || (Node == Edge[1] && Adj == Edge[0]))
                {
                    continue;
                }
                if(Adj != Parent)
                {
                    BFS.emplace(Adj, Node);
                }
            }
        }

        for(bool Visit : Visited)
        {
            if(!Visit)
                return false;
        }
        return true;
    }
};