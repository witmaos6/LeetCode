class DSU
{
    vector<int> parent;
    vector<int> rank;

    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findPar(int u){

        if(parent[u] != u){
            parent[u] = findPar(parent[u]);
        }

        return parent[u];
    }

    void unionByRank(int u , int v){

        int par_u = findPar(u);
        int par_v = findPar(v);

        if(par_u == par_v) return;

        if(rank[par_u] < rank[par_v]){
            parent[par_u] = par_v;
        }else if(rank[par_u] < rank[par_v]){
            parent[par_v] = par_u;
        }else{
            parent[par_u] = par_v;
            rank[par_u]++;
        }
    }

    void unionByLex(int u, int v){

        int par_u = findPar(u);
        int par_v = findPar(v);

        if(par_u == par_v) return;

        if(par_u > par_v){
            parent[par_u] = par_v;
        }else{
            parent[par_v] = par_u;
        }
    }
};

class Solution {
    using Pair = pair<int, int>;
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        const int N = static_cast<int>(s1.size());
        vector<Pair> Pairs;

        for(int i = 0; i < N; i++)
        {
            int C1 = s1[i] - 'a';
            int C2 = s2[i] - 'a';

            if(C1 != C2)
            {
                Pair Temp = {C1, C2};
                if(C1 > C2)
                {
                    Temp = {C2, C1};
                }
                Pairs.push_back(Temp);
            }
        }

        sort(Pairs.begin(), Pairs.end());

        DSU Dsu = DSU(26);

        for(auto&[U, V] : Pairs)
        {
            if(Dsu.findPar(U) != Dsu.findPar(V))
            {
                Dsu.unionByLex(U, V);
            }
        }

        const int BaseSize = static_cast<int>(baseStr.size());
        for(int i = 0; i < BaseSize; i++)
        {
            int K = (baseStr[i] - 'a');

            int Par = Dsu.findPar(K);
            baseStr[i] = Par + 'a';
        }

        return baseStr;
    }
};