class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k)
    {
        vector<vector<int>> Graph1 = BuildGraph(edges1);
        vector<vector<int>> Graph2 = BuildGraph(edges2);

        const int Graph1Size = static_cast<int>(Graph1.size());
        const int Graph2Size = static_cast<int>(Graph2.size());

        vector<int> Result(Graph1Size);
        int MaxValue = 0;

        for(int i = 0; i < Graph2Size; i++)
        {
            MaxValue = max(MaxValue, DFS(Graph2, i, -1, k - 1));
        }
        for(int i = 0; i < Graph1Size; i++)
        {
            Result[i] = DFS(Graph1, i, -1, k) + MaxValue;
        }
        return Result;
    }
private:
    vector<vector<int>> BuildGraph(const vector<vector<int>>& Edges)
    {
        vector<vector<int>> Graph(Edges.size() + 1);
        for(const vector<int>& Edge : Edges)
        {
            Graph[Edge[0]].push_back(Edge[1]);
            Graph[Edge[1]].push_back(Edge[0]);
        }
        return Graph;
    }

    int DFS(const vector<vector<int>>& Graph, int U, int P, int K)
    {
        if(K < 0)
            return 0;
        int Count = 1;
        for(const int& V : Graph[U])
        {
            if(V != P)
            {
                Count += DFS(Graph, V, U, K - 1);
            }
        }
        return Count;
    }
};