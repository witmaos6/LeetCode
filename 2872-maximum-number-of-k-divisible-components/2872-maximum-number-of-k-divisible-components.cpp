class Solution {
    vector<vector<int>> Graph;
    vector<long long> SubValue;
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k)
    {
        Graph.resize(values.size());
        
        for(vector<int>& Edge : edges)
        {
            Graph[Edge[0]].push_back(Edge[1]);
            Graph[Edge[1]].push_back(Edge[0]);
        }
        
        SubValue.resize(n);
        
        DFS(0, -1, values);
        return MaxK(0, -1, k);
    }
private:    
    long long DFS(int Node, int Parent, vector<int>& Values)
    {
        long long Result = 0;
        long long Sum = Values[Node];
        
        for(int& Neighbor : Graph[Node])
        {
            if(Neighbor == Parent)
            {
                continue;
            }
            
            Sum += DFS(Neighbor, Node, Values);
        }
        return SubValue[Node] = Sum;
    }
    
    int MaxK(int Node, int Parent, const int K)
    {
        int Result = 1;
        for(int& Neighbor : Graph[Node])
        {
            if(Neighbor == Parent)
            {
                continue;
            }
            if(SubValue[Neighbor] % K == 0)
            {
                Result += MaxK(Neighbor, Node, K);
            }
            else
            {
                Result += MaxK(Neighbor, Node, K) - 1;
            }
        }
        
        return Result;
    }
};