class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges)
    {
        vector<int> UnionFind(n);
        for(int i = 0; i < n; i++)
        {
            UnionFind[i] = i;
        }
        
        for(vector<int>& Edge : edges)
        {
            UnionFind[Edge[1]] = Edge[0];
        }
        
        vector<int> Result;
        for(int i = 0; i < n; i++)
        {
            if(UnionFind[i] == i)
            {
                Result.push_back(i);
            }
        }
        
        return Result;
    }
};