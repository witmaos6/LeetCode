class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        const int N = static_cast<int>(graph.size());
        
        vector<int> Colors(N);
        queue<int> BFS;
        
        for(int i = 0; i < N; i++)
        {
            if(Colors[i])
                continue;
            
            Colors[i] = 1;
            BFS.push(i);
            
            while(!BFS.empty())
            {
                int CurrNode = BFS.front();
                
                for(int& Node : graph[CurrNode])
                {
                    if(!Colors[Node])
                    {
                        Colors[Node] = -Colors[CurrNode];
                        BFS.push(Node);
                    }
                    else if(Colors[Node] == Colors[CurrNode])
                    {
                        return false;
                    }
                }
                BFS.pop();
            }
            
        }
        
        return true;
    }
};