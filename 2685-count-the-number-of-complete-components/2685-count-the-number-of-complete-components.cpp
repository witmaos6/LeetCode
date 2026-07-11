class UnionFind
{
    vector<int> Parents;

public:
    UnionFind(int Size = 1)
    {
        Parents.resize(Size);
        for(int i = 0; i < Size; i++)
        {
            Parents[i] = i;
        }
    }

    void Union(int U, int V)
    {
        int PU = Find(U);
        int PV = Find(V);

        if(PU == PV)
            return;
        
        Parents[PV] = PU;
    }

    int Find(int X)
    {
        if(Parents[X] == X)
            return X;
        
        return Parents[X] = Find(Parents[X]);
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges)
    {
        UnionFind UF(n);

        vector<int> Count(n);
        vector<int> Size(n);

        for(vector<int>& Edge : edges)
        {
            int U = Edge[0];
            int V = Edge[1];

            int PU = UF.Find(U);
            int PV = UF.Find(V);

            UF.Union(PU, PV);
        }

        for(vector<int>& Edge : edges)
        {
            int U = Edge[0];
            int V = Edge[1];

            int PU = UF.Find(U);
            Count[PU]++;
        }

        for(int i = 0; i < n; i++)
        {
            int Pa = UF.Find(i);
            Size[Pa]++;
        }

        int Result = 0;
        for(int i = 0; i < n; i++)
        {
            if(Size[i] == 0)
                continue;
            
            int K = Size[i];
            if(Count[i] == (K * (K - 1) / 2))
            {
                Result++;
            }
        }
        return Result;
    }
};