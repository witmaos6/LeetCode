class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2)
    {
        int D1 = GetDiameter(edges1);
        int D2 = GetDiameter(edges2);
        
        return max(max(D1 - 1, D2 - 1), D1 / 2 + D2 / 2 + 1);
    }    
private:
    int GetDiameter(vector<vector<int>>& Edges)
    {
        unordered_map<int, vector<int>> Table;
        for(vector<int>& Edge : Edges)
        {
            Table[Edge[0]].push_back(Edge[1]);
            Table[Edge[1]].push_back(Edge[0]);
        }
        
        int Result = 0;
        DFS(0, -1, Table, Result);
        return Result;
    }
    
    int DFS(int Node, int Parent, unordered_map<int, vector<int>>& Table, int& Result)
    {
        int MaxDepth = 1;
        for(int Neighbor : Table[Node])
        {
            if(Neighbor == Parent)
                continue;
            
            int Depth = DFS(Neighbor, Node, Table, Result);
            Result = max(Result, MaxDepth + Depth);
            MaxDepth = max(MaxDepth, Depth + 1);
        }
        return MaxDepth;
    }
};