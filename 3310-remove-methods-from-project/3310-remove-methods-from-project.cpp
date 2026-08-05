class Solution {
    vector<vector<int>> Graph;
    vector<bool> Visited;
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations)
    {
        Graph.resize(n);

        for(vector<int>& UV : invocations)
        {
            Graph[UV[0]].push_back(UV[1]);
        }

        Visited.resize(n);
        DFS(k);

        for(vector<int>& UV : invocations)
        {
            if(Visited[UV[0]])
                continue;
            
            if(Visited[UV[1]])
            {
                vector<int> Result;
                for(int i = 0; i < n; i++)
                {
                    Result.push_back(i);
                }
                return Result;
            }
        }

        vector<int> Result;
        for(int i = 0; i < n; i++)
        {
            if(!Visited[i])
            {
                Result.push_back(i);
            }
        }
        return Result;
    }

private:
    void DFS(int U)
    {
        Visited[U] = true;
        for(int& V : Graph[U])
        {
            if(Visited[V])
                continue;
            DFS(V);
        }
    }
};