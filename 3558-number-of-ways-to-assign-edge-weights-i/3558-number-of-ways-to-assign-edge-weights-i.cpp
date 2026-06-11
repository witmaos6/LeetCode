class Solution {
    const int Mod = 1e9 + 7;
    vector<vector<int>> Arr;
public:
    int assignEdgeWeights(vector<vector<int>>& edges)
    {
        const int N = edges.size() + 1;
        Arr.resize(N + 1);

        for(vector<int>& Edge : edges)
        {
            Arr[Edge[0]].push_back(Edge[1]);
            Arr[Edge[1]].push_back(Edge[0]);
        }

        return Pow(2, DFS(1, 0) - 1);
    }

    int DFS(int Node, int Prev)
    {
        int Result = 0;

        for(int& X : Arr[Node])
        {
            if(X != Prev)
            {
                Result = max(Result, DFS(X, Node) + 1);
            }
        }
        return Result;
    }

    long long Pow(long long Base, int Exp)
    {
        long long Result = 1;
        while(Exp)
        {
            if(Exp & 1)
            {
                Result = Result * Base % Mod;
            }

            Base = Base * Base % Mod;
            Exp >>= 1;
        }
        return Result;
    }
};