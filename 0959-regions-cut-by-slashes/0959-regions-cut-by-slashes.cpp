class UnionFind
{
    vector<int> root, Size;
public:
    int merge;
    UnionFind(int N) : root(N), Size(N, 1), merge(0)
    {
        iota(root.begin(), root.end(), 0);
    }

    bool Union(int x, int y)
    {
        x = Find(x), y = Find(y);

        if (x == y) return false;

        if (Size[x] > Size[y])
        {
            Size[x] += Size[y];
            root[y] = x;
        } else {
            Size[y] += Size[x];
            root[x] = y;
        }
        merge++;
        return true;
    }
    
    int Find(int x)
    {
        if (x == root[x])
            return x;
        return root[x] = Find(root[x]);
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid)
    {
        const int N = static_cast<int>(grid.size());
        const int Side = N + 1;
        const int Square = Side * Side;

        bitset<962> Vertex = 0;
        UnionFind G(Square);

        int N0 = Square - Side;
        Vertex[0] = 1;
        Vertex[N0] = 1;

        for (int i = 0; i < N; i++)
        {
            Vertex[i + 1] = 1;
            G.Union(i, i + 1);
            
            Vertex[i + N0 + 1] = 1;
            G.Union(i + N0, i + N0 + 1);

            Vertex[i * Side] = 1;
            G.Union(i * Side, i * Side + Side);

            Vertex[N + i * Side] = 1;
            G.Union(N + i * Side, N + (i + 1) * Side);
        }

        int E = 4 * N;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == '\\')
                {
                    int U = i * Side + j;
                    int V = (i + 1) * Side + j + 1;
                    Vertex[U] = 1;
                    Vertex[V] = 1;
                    G.Union(U, V);
                    E++;
                } 
                else if (grid[i][j] == '/')
                {
                    int U = i * Side + j + 1;
                    int V = (i + 1) * Side + j;
                    Vertex[U] = 1;
                    Vertex[V] = 1;
                    G.Union(U, V);
                    E++;
                }
            }
        }

        int V = Vertex.count();
        int Component = max(1, V - G.merge);
        int F = E - V + 1 + Component;
        
        return F - 1;
    }
};