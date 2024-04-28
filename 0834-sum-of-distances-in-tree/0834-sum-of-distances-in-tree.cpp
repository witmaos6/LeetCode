class Solution {
    vector<vector<int>> Adj;
    vector<int> Sum;
    vector<int> Count;
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
    {
        if(n == 1)
            return {0};
        
        Adj.resize(n);
        for(const vector<int>& Edge : edges)
        {
            int U = Edge[0];
            int V = Edge[1];
            Adj[U].push_back(V);
            Adj[V].push_back(U);
        }
        
        Sum.resize(n, 0);
        Count.resize(n, 1);
        
        DFS(0, -1);
        Reroot(0, -1, n);
        
        return Sum;
    }
    
private:
    void DFS(const int NodeIndex, const int Parent)
    {
        for(int NextNode : Adj[NodeIndex])
        {
            if(NextNode == Parent)
                continue;
            
            DFS(NextNode, NodeIndex);
            
            Count[NodeIndex] += Count[NextNode];
            Sum[NodeIndex] += Sum[NextNode] + Count[NextNode];
        }
    }
    
    void Reroot(const int CurrNode, const int Parent, const int N)
    {
        for(int NextNode : Adj[CurrNode])
        {
            if(NextNode == Parent)
                continue;
            
            Sum[NextNode] = Sum[CurrNode] + N - (2 * Count[NextNode]);
            Reroot(NextNode, CurrNode, N);
        }
    }
};