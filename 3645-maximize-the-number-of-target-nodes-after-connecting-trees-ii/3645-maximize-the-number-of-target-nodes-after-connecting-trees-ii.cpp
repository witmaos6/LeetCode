class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2)
    {
        vector<vector<int>> Graph1 = BuildGraph(edges1);
        vector<vector<int>> Graph2 = BuildGraph(edges2);

        const int Graph1Size = static_cast<int>(Graph1.size());
        const int Graph2Size = static_cast<int>(Graph2.size());

        vector<int> Memo1(Graph1Size, -1);
        Memo1[0] = 0;
        int Even1 = 0, Odd1 = 0;
        DFS(Graph1, 0, -1, Memo1, Even1, Odd1);

        vector<int> Memo2(Graph2Size, -1);
        Memo2[0] = 0;
        int Even2 = 0, Odd2 = 0;
        DFS(Graph2, 0, -1, Memo2, Even2, Odd2);

        int Max2 = max(Even2, Odd2);
        vector<int> Result(Graph1.size());
        for(int i = 0; i < Graph1Size; i++)
        {
            Result[i] = (Memo1[i] == 0 ? Even1 : Odd1) + Max2;
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

    void DFS(const vector<vector<int>>& Graph, int U, int Parent, vector<int>& Memo, int& EvenCount, int& OddCount)
    {
        if(Memo[U] == 0)
        {
            EvenCount++;
        }
        else
        {
            OddCount++;
        }

        for(const int& V : Graph[U])
        {
            if(V != Parent)
            {
                Memo[V] = Memo[U] ^ 1;
                DFS(Graph, V, U, Memo, EvenCount, OddCount);
            }
        }
    }
};