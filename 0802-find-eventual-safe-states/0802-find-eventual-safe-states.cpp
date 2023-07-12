class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        const int N = static_cast<int>(graph.size());
        vector<vector<int>> Reverse(N);
        vector<int> Terminals(N);
        queue<int> BFS;
        for(int i = 0; i < N; i++)
        {
            for(int Connected : graph[i])
            {
                Reverse[Connected].push_back(i);
            }
            
            Terminals[i] = static_cast<int>(graph[i].size());
            if(Terminals[i] == 0)
                BFS.push(i);
        }
        
        vector<bool> bIsSafes(N);
        while(!BFS.empty())
        {
            int Node = BFS.front();
            BFS.pop();
            bIsSafes[Node] = true;
            
            for(int Prev : Reverse[Node])
            {
                Terminals[Prev]--;
                if(Terminals[Prev] == 0)
                    BFS.push(Prev);
            }
        }
        
        vector<int> Result;
        for(int i = 0; i < N; i++)
        {
            if(bIsSafes[i])
                Result.push_back(i);
        }
        
        return Result;
    }
};