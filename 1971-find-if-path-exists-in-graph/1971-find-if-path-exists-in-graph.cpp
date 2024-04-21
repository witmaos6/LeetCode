class Solution {
    vector<int> Union;
    vector<int> Size;
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        Union.resize(n);
        Size.resize(n, 1);
        
        for(int i = 0; i < n; i++)
        {
            Union[i] = i;
        }

        for(const vector<int>& Edge : edges)
        {
            UnionFind(Edge[0], Edge[1]);
            
            if(Union[source] == Union[destination])
                return true;
        }
        
        return Find(source) == Find(destination);
    }    
private:
    void UnionFind(int U, int V)
    {
        U = Find(U);
        V = Find(V);
        
        if(U == V)
            return;
        
        if(Size[U] > Size[V])
        {
            swap(U, V);
        }
        
        Union[U] = V;
        Size[V] += Size[U];
    }
    
    int Find(int U)
    {
        while(U != Union[U])
        {
            U = Union[U];
        }
        return U;
    }
};