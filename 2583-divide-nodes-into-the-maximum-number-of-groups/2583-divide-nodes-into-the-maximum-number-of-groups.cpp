class Solution {
    vector<vector<int>> Graph;
    vector<int> Memo;
public:
    int magnificentSets(int n, vector<vector<int>>& edges)
    {
        Graph.resize(n + 1);
        Memo.resize(n + 1, -1);

        for(vector<int>& Edge : edges)
        {
            Graph[Edge[0]].push_back(Edge[1]);
            Graph[Edge[1]].push_back(Edge[0]);
        }

        int MaxGroup = 0;
        for(int i = 1; i <= n; i++)
        {
            if(Memo[i] != -1)
                continue;

            unordered_set<int> Nodes;
            FindConnectedNode(i, Nodes);

            int MaxDepth = -1;
            for(const int& Node : Nodes)
            {
                int Depth = GetMaxDepth(Node, Nodes);
                MaxDepth = max(MaxDepth, Depth);
            }
            
            if(MaxDepth == -1)
            {
                return -1;
            }
            MaxGroup += MaxDepth;
        }

        return MaxGroup;
    }
private:
    void FindConnectedNode(int Node, unordered_set<int>& Nodes)
    {
        Nodes.insert(Node);
        for(int& Adj : Graph[Node])
        {
            if(Nodes.find(Adj) == Nodes.end())
            {
                FindConnectedNode(Adj, Nodes);
            }
        }
    }

    int GetMaxDepth(int Begin, unordered_set<int>& Nodes)
    {
        for(const int& Node : Nodes)
        {
            Memo[Node] = -1;
        }

        Memo[Begin] = 1;
        queue<int> Q;
        Q.push(Begin);

        int Depth = 1;

        while(!Q.empty())
        {
            int CurrNode = Q.front();
            Q.pop();

            for(int& Adj : Graph[CurrNode])
            {
                if(Memo[Adj] == -1)
                {
                    Memo[Adj] = Memo[CurrNode] + 1;
                    Depth = max(Depth, Memo[Adj]);
                    Q.push(Adj);
                }
                else if(abs(Memo[CurrNode] - Memo[Adj]) != 1)
                {
                    return -1;
                }
            }
        }

        return Depth;
    }
};