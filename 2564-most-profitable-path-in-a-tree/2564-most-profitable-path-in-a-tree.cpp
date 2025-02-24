class Solution {
    unordered_map<int, vector<int>> Adjs;
    unordered_map<int, vector<int>> Tree;
    map<int, int> Visited;
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount)
    {
        const int N = static_cast<int>(edges.size()) + 1;

        for(int i = 0; i < N - 1; i++)
        {
            Adjs[edges[i][0]].push_back(edges[i][1]);
            Adjs[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> Added(N);
        Added[0] = 1;
        queue<int> BFS;
        BFS.push(0);
        while(!BFS.empty())
        {
            int Node = BFS.front();
            BFS.pop();

            for(int& Adj : Adjs[Node])
            {
                if(Added[Adj] == 0)
                {
                    Added[Adj]++;
                    Tree[Node].push_back(Adj);
                    BFS.push(Adj);
                }
            }
        }

        vector<int> Parent(N);
        for(int i = 0; i < N; i++)
        {
            for(int& Child : Tree[i])
            {
                Parent[Child] = i;
            }
        }

        int Time = 0;
        int Node = bob;
        while(Node != 0)
        {
            Visited[Node] = Time++;
            Node = Parent[Node];
        }

        return DFS(0, 0, amount);
    }
private:
    int DFS(int Node, int Time, vector<int>& Amount)
    {
        int CurrValue = Amount[Node];
        if(Visited.count(Node))
        {
            if(Visited[Node] < Time)
            {
                CurrValue = 0;
            }
            else if(Visited[Node] == Time)
            {
                CurrValue /= 2;
            }
        }
        if(Tree[Node].size() == 0)
        {
            return CurrValue;
        }

        int Result = INT_MIN;
        for(int& Adj : Tree[Node])
        {
            int Temp = DFS(Adj, Time + 1, Amount);
            Result = max(Result, Temp);
        }
        return CurrValue + Result;
    }
};