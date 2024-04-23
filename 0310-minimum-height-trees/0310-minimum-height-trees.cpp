class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        if(n == 1)
            return {0};
        
        unordered_map<int, vector<int>> Tree;
        vector<int> Degree(n);
        for(vector<int>& Edge : edges)
        {
            const int U = Edge[0], V = Edge[1];
            Tree[U].push_back(V);
            Tree[V].push_back(U);
            Degree[V]++;
            Degree[U]++;
        }
        
        queue<int> Leaves;
        for(int i = 0; i < n; i++)
        {
            if(Degree[i] == 1)
            {
                Leaves.push(i);
            }
        }
        
        int RemainNodes = n;
        while(RemainNodes > 2)
        {
            int NrOfLeaves = Leaves.size();
            RemainNodes -= NrOfLeaves;
            for(int i = 0; i < NrOfLeaves; i++)
            {
                int Leaf = Leaves.front();
                Leaves.pop();
                for(int AdjNode : Tree[Leaf])
                {
                    Degree[AdjNode]--;
                    if(Degree[AdjNode] == 1)
                    {
                        Leaves.push(AdjNode);
                    }
                }
            }
        }
        
        vector<int> Result;
        while(!Leaves.empty())
        {
            Result.push_back(Leaves.front());
            Leaves.pop();
        }
        return Result;
    }
};