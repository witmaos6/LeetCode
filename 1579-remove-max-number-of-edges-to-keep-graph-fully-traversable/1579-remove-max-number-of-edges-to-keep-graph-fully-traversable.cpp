class UnionFind {
    vector<int> Root, Size;
    int Components;
public:
    UnionFind(int n): Root(n + 1), Size(n + 1, 1), Components(n)
    {
        iota(Root.begin(), Root.end(), 0);
    }
    
    int Find(int x) 
    {
        if (x == Root[x]) 
            return x;
        
        return Root[x] = Find(Root[x]);
    }

    bool Union(int x, int y)
    {
        x = Find(x), y = Find(y);
        
        if (x == y) return 0;
        
        if (Size[x] > Size[y])
        {
            Size[x] += Size[y];
            Root[y] = x;
        } 
        else
        {
            Size[y] += Size[x];
            Root[x] = y;
        }       
        Components--;
        return 1;
    }

    bool IsConnected()
    {
        return Components == 1;
    }
        
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges)
    {
        UnionFind Alice(n), Bob(n);

        int EdgesNeed = 0;
        
        for (vector<int>& Edge : edges)
        {
            if (Edge[0] == 3)
            {
                EdgesNeed += (Alice.Union(Edge[1], Edge[2]) | Bob.Union(Edge[1], Edge[2]));
            }
        }
        
        for (vector<int>& Edge : edges)
        {
            if (Edge[0] == 1)
            {
                EdgesNeed += Alice.Union(Edge[1], Edge[2]);
            }
            else if (Edge[0]==2)
            {
                EdgesNeed += Bob.Union(Edge[1], Edge[2]);
            }
        }

        if (Alice.IsConnected() && Bob.IsConnected())
        {
            return edges.size() - EdgesNeed;
        }
            
        return -1;
    }
};